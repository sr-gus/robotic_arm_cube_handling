import cv2
import numpy as np
import paho.mqtt.client as mqtt

MQTT_BROKER = "192.168.100.45"
MQTT_PORT = 1883

TOPICS = {
    "camera0_image_raw": "ros/camera0/image_raw",
    "camera0_color_mask": "ros/camera0/color_mask",
    "camera0_canny_edges": "ros/camera0/canny_edges",
    "camera0_final_output": "ros/camera0/final_output",
    "camera1_image_raw": "ros/camera1/image_raw",
    "camera1_color_mask": "ros/camera1/color_mask",
    "camera1_canny_edges": "ros/camera1/canny_edges",
    "camera1_final_output": "ros/camera1/final_output"
}

images = {
    "camera0_image_raw": None,
    "camera0_color_mask": None,
    "camera0_canny_edges": None,
    "camera0_final_output": None,
    "camera1_image_raw": None,
    "camera1_color_mask": None,
    "camera1_canny_edges": None,
    "camera1_final_output": None
}

click_x, click_y = -1, -1

current_camera = "camera1"

def on_mouse_click(event, x, y, flags, param):
    global click_x, click_y
    if event == cv2.EVENT_LBUTTONDOWN:
        click_x, click_y = x, y

def on_connect(client, userdata, flags, rc):
    print("Connected to MQTT Broker!" if rc == 0 else f"Failed to connect, return code {rc}")
    for topic in TOPICS.values():
        client.subscribe(topic)

def on_message(client, userdata, msg):
    nparr = np.frombuffer(msg.payload, np.uint8)
    image = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    for key, topic in TOPICS.items():
        if msg.topic == topic:
            images[key] = image

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(MQTT_BROKER, MQTT_PORT, 60)
client.loop_start()

cv2.namedWindow("raw_image")
cv2.namedWindow("color_mask")
cv2.namedWindow("canny_edges")
cv2.namedWindow("final_output")
cv2.setMouseCallback("raw_image", on_mouse_click)

try:
    while True:
        raw_image_key = f"{current_camera}_image_raw"
        color_mask_key = f"{current_camera}_color_mask"
        canny_edges_key = f"{current_camera}_canny_edges"
        final_output_key = f"{current_camera}_final_output"

        if images[raw_image_key] is not None:
            cv2.imshow("raw_image", images[raw_image_key])
            if click_x >= 0 and click_y >= 0:
                hsv_image = cv2.cvtColor(images[raw_image_key], cv2.COLOR_BGR2HSV)
                hsv_value = hsv_image[click_y, click_x]
                print(f"HSV at ({click_x}, {click_y}) in {current_camera} raw image: {hsv_value}")
                click_x, click_y = -1, -1

        if images[color_mask_key] is not None:
            cv2.imshow("color_mask", images[color_mask_key])

        if images[canny_edges_key] is not None:
            cv2.imshow("canny_edges", images[canny_edges_key])

        if images[final_output_key] is not None:
            cv2.imshow("final_output", images[final_output_key])

        key = cv2.waitKey(1) & 0xFF
        if key == ord('c'):
            current_camera = "camera1" if current_camera == "camera0" else "camera0"
            print(f"Switched to {current_camera}")

        if key == ord('q'):
            break

finally:
    client.loop_stop()
    cv2.destroyAllWindows()
