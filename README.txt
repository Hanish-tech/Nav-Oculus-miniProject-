nav-IRIS is a project that uses Machine Learning to recognize traffic signs, interpret their meaning, and manage bot movement.

1. ESP 32 CAM
To upload code to the ESP32-CAM, follow these steps:

a. Install the ESP32 board package:
   - Open Arduino IDE.
   - Go to File > Preferences and add `https://dl.espressif.com/dl/package_esp32_index.json` in "Additional Board Manager URLs".
   - Open Tools > Board > Board Manager and search for ESP32(version 2.0.8 or 2.0.10) , then install it.

b. Select ESP32-CAM board:
   - Choose "AI-Thinker ESP32-CAM" from the board menu.

c. Connect ESP32-CAM:
   - Use a USB-to-Serial adapter (connect TX pin of ESP32 cam to arudion pin 11, 3.3V, GND, and IO0 to GND for flashing).

d. Upload code
   - Press "Upload" in the Arduino IDE.
Use the google teachable machine to train the model with different traffic sign
Train the model export the model and upload it to the cloud, copy the link and paste it in the ESP32 cam IP server and click on load model.