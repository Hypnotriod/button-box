# button-box

## Docs

* [Human Interface Devices (HID) Specifications](https://www.usb.org/hid)
* [Usage Table (page 32)](https://usb.org/sites/default/files/hut1_4.pdf)
* [Simulation Controls (page 61)](https://usb.org/sites/default/files/hut1_4.pdf)

## Device report descriptor template example (usbd_hid.c)

```C
  0x05, 0x01, // Usage Page (Generic Desktop)
  0x09, 0x05, // 0x05 - USAGE (Gamepad), 0x04 - USAGE (Joystick)
  0xA1, 0x01, // Collection (Application)

  // Usage Generic Desktop Pointer
  0x05, 0x01, // Usage Page (Generic Desktop)
  0x09, 0x01, // Usage (Pointer)
  0xA1, 0x00, // Collection (Physical)
  0x09, 0x??, // 0x30 - X, 0x31 - Y, 0x32 - Z, 0x33 - Rx, 0x34 - Ry, 0x35 - Rz, 0x40 - Vx, 0x41 - Vy, 0x42 - Vz, 0x43 - Vbrx, 0x44 - Vbry, 0x45 - Vbrz, 0x45 - Vno
  // ... duplicate line above for each axis of a pointer unit
  0x15, 0x81, // Logical Minimum (-127)
  0x25, 0x7F, // Logical Maximum (127)
//  0x15, 0x00, // Logical Minimum (0)
//  0x26, 0x00, 0x10, // Logical Maximum (4096) 
  0x75, 0x08, // Report Size (8)
//  0x75, 0x10, // Report Size (16)
  0x95, 0x??, // Report Count (x) (axis count)
  0x81, 0x02, // Input (Data,Var,Abs)
  0xC0, // End Collection

  // Usage Simulation Controls
  0x05, 0x02, // Usage Page (Simulation Controls)
  0x09, 0x??, // 0xc5 - Brake, 0xc6 - Clutch, 0xc7 - Shifter ... (Please refer to Simulation Controls Page for the full list)
  0x15, 0x81, // Logical Minimum (-127)
  0x25, 0x7F, // Logical Maximum (127)
//  0x15, 0x00, // Logical Minimum (0)
//  0x26, 0x00, 0x10, // Logical Maximum (4096) 
  0x75, 0x08, // Report Size (8)
//  0x75, 0x10, // Report Size (16)
  0x75, 0x10, // Report Size (16)
  0x95, 0x01, // Report Count (1)
  0x81, 0x02, // Input (Data,Var,Abs)

  // Usage Buttons
  0x05, 0x09, // Usage Page (Button)
  0x19, 0x01, // Usage Minimum (Button 1)
  0x29, 0x??, // Usage Maximum (Button x) (buttons count)
  0x15, 0x00, // Logical Minimum (0)
  0x25, 0x01, // Logical Maximum (1)
  0x75, 0x01, // Report Size (1)
  0x95, 0x??, // Report Count (x) (buttons count)
  0x81, 0x02, // Input (Data,Var,Abs)
  0x95, 0x??, // Report Count (n) (remaining bits alignment: the number of bytes to accommodate the number of buttons (1 bit per button) multiplied by 8, minus the number of buttons)
  0x81, 0x03, // Input (Constant,Var,Abs)

  // End Collection (Application)
  0xC0, // End Collection
```
