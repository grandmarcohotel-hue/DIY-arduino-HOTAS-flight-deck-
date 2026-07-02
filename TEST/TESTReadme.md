# TEST 

This is a step-by-step guide to the testing grounds. This setup will allow the testing of connections between an Arduino Pro Micro, a computer, multiple rotary potentiometers, and button modules.

> ⚠️ **Note:** This is only a test setup, not a finished product.

---

## Hardware Section

### Bill of Materials
* **Arduino Pro Micro**
* **DuPont Wires (M-M and M-F)**: 
  * 2 M-M total for the Arduino power lines.
  * 3 M-F per potentiometer.
  * 2 M-F per button.
* **Rotary Potentiometers & Button Modules**: Keep it simple by using up to 6 pots and buttons total.
* **USB Data Cable**: To connect the Arduino to your computer.
* **Breadboard**

*For the full, detailed names and types of these components, please refer to the hardware list in the main repository file.*

---

### Step-by-Step Hardware Assembly

#### Step 1: Mounting the Arduino
Regardless of what kind of breadboard you have, plug the Arduino into any holes that are **not** on the blue (-) or red (+) power rails. Leave enough room so that there are empty holes on either side of the Arduino's rows.

* **💡 Tip:** The Arduino won’t easily snug into the holes, so apply extra force to one side using a towel or something soft. Plug it in so that one side of the Arduino’s pins are all the way in and the board is slanted. Don’t panic—the pins aren’t bending! Once one side is fully seated inside the holes, press the opposite side down.

#### Step 2: Powering the Board
Look for the **GND** and **VCC** labels printed on your Arduino. Take 2 Male-to-Male (M-M) wires and route them exactly like this:
* Connect the hole right next to a **GND pin** $\rightarrow$ any hole on the **blue (-) rail**.
* Connect the hole right next to the **VCC pin** $\rightarrow$ any hole on the **red (+) rail**.

#### Step 3: Preparing the Modules
Gather the pots and buttons you want to use for your test layout. *(Note: Because of Map Connect v2, you can use a maximum of 6 rotary pots).*
* **For Pots:** Grab 3 Female-to-Male (M-F) DuPont wires. Push the Female sides (the side with the socket) onto the 3 pins of the potentiometer.
* **For Buttons:** Grab 2 Female-to-Male (M-F) DuPont wires. Push the Female sides onto the **OUT/S** pin and the **(-)** pin of the button.
* **💡 Tip:** Use small strips of tape to bundle the individual wire groups of each pot and button together. It will keep your test bench drastically cleaner and easier to read.

#### Step 4: Final Routing to the Board
Take your wired components and connect their remaining Male pins to the breadboard using these mapping rules:

##### For Potentiometers:
* Connect the **GND** wire $\rightarrow$ a hole along the **SAME blue (-) rail** used by the Arduino.
* Connect the **VCC** wire $\rightarrow$ a hole along the **SAME red (+) rail** used by the Arduino.
* Connect the **OUT** wire $\rightarrow$ a hole directly adjacent to any of these analog Arduino pins: `A0`, `A1`, `A2`, `A3`, `4`, `6`, `8`, `9`, or `10`.

##### For Buttons:
* Connect the **GND / (-)** wire $\rightarrow$ a hole along the **SAME blue (-) rail** used by the Arduino.
* Connect the **OUT / S** wire $\rightarrow$ a hole directly adjacent to any of the remaining digital Arduino pins: `2`, `3`, `5`, `7`, `14`, `15`, or `16`.

#### Step 5: Powering On
Once every pot and button you want to test is safely connected, connect your Arduino to your computer using your USB data cable. The red power LEDs on the board should illuminate instantly, verifying a successful connection.

---

## Coding Section

#### Step 1: Download the Arduino IDE app on your computer
Search **"Arduino IDE"** on your browser and click the link for the official Arduino website. From there, download the installer that matches your computer’s operating system (Windows/macOS). Once the download finishes, find the file and run the installer. During the installation process, make sure to accept any prompts asking for permission to install "drivers." *(This is just to make sure your computer can talk to the board later!)*

#### Step 2: Download the 'Joystick' library for Arduino
Search **"joystick library by mheironimus"** on your browser and click the first GitHub link. Click the **"Download"** link or button on that page to save the `.zip` library file to your computer.

#### Step 3: Configure the Arduino IDE
Open the Arduino IDE app. You can use the fresh, empty "sketch" that pops up automatically. 
1. In the top menu, go to **Sketch** -> **Include Library** -> **Add .ZIP Library...** A file manager window will pop up; select the joystick library `.zip` file you just downloaded.
2. Next, click the **Select Board** dropdown at the top and click **Select other board and port...**
3. Under the **Boards** column, search for **"Arduino Leonardo"** *(chillax, it uses the exact same chip layout as the Arduino Pro Micro for this project).*
4. Under the **Ports** column, select your board's serial port (for example, `COM7 Serial Port (USB)`), and click **OK**.

#### Step 4: Add the base code
Copy the C++ program from your `test.ino` file and paste it directly into the empty Arduino IDE sketch page. We will modify this base code depending on exactly how many potentiometers (pots) and buttons you have hooked up to your breadboard.

#### Step 5: Update the Joystick profile layout
Look at the configuration block near the very top of the code where the joystick layout is initialized. 
* Locate the line with the numbers `1, 0,` and change the `1` to match the total number of physical buttons you are connecting.
* Below that line, look for the axis lines filled with `true` and `false` values. Each `true` represents an active potentiometer axis. Toggle these to `true` or `false` sequentially to match your layout.
  * *Example if 2 pots:* `true, true, false, false, false, false,`
  * *Example if 6 pots:* `true, true, true, true, true, true,`

#### Step 6: Declare your physical button pins
Look for the statement starting with `const int buttonPin = 15;`. Duplicate this line line-by-line for every single button you want to add. As you copy it, you must change the word `button` inside `buttonPin` to a unique name for each entry, such as `button2Pin` or `button3Pin`. Finally, replace the number `15` with the actual physical Arduino digital pin number that your button's **OUT/S** pin is plugged into.
* *Example if 3 buttons are connected to pins 7, 6, and 8 on the Arduino:*  
  `const int buttonPin = 7;`  
  `const int button2Pin = 6;`  
  `const int button3Pin = 8;`

#### Step 7: Turn on the button pins in setup
Move down to the `void setup()` block and look for the line reading `pinMode(buttonPin, INPUT_PULLUP);`. Duplicate this line inside the brackets for every button you have. Make sure the pin name you type inside the parentheses matches the unique variable names you just created back in **Step 6**.

#### Step 8: Configure your potentiometers (Pots)
Look inside the `void loop()` block for the analog input readings starting with `int pot1 = analogRead(A0);`. Add or delete these lines until the total number matches your physical pots. Give each one a unique tracking name like `pot1`, `pot2`, or `pot3`. Match the pin name inside the parentheses to where it is plugged into the Arduino. 
* *Example if a pot is connected to an analog pin like A1:* `int pot1 = analogRead(A1);`
* *Example if a pot is connected to a digital pin like pin 4:* `int pot1 = analogRead(A4);`

Directly below those lines, look for the matching `Joystick.setXAxis(pot1);` lines that feed data to Windows. Add or delete these commands to pass your readings through. Change the name inside the parentheses to match your new pot variable name, and change the axis letters sequentially (the 5th axis becomes `setRyAxis`, the 6th becomes `setRzAxis`).

#### Step 9: Write the button readings loop
Look at the button reading section at the bottom of the loop which begins with `int buttonState = digitalRead(buttonPin);` followed by an `if-else` condition testing if the state is `LOW`. Duplicate this entire reading block from the state variable down to the closing bracket for each extra button you are using. For each new block you paste in:
* Change the state name and pin name to match the unique buttons you set up back in **Step 6**.
* Change the first number inside the `Joystick.setButton` parentheses. Windows indexes buttons starting from `0`. So for Button 1 use `0`, for Button 2 use `1`, for Button 3 use `2`, and keep increasing the number sequentially for every button you add.

#### Step 10: Upload and fly!
Once all your edits are complete, connect your Arduino to your computer with the Data cable and click **Sketch** -> **Upload** (or click the **Arrow icon** at the top left). 

Open up a web-based gamepad tester, launch your favorite flight simulator, or open your game's controller layout settings menu to map your custom hardware axes and buttons. Enjoy!
