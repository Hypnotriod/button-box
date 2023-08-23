# button-box

## Docs

* [Human Interface Devices (HID) Specifications](https://www.usb.org/hid)
* [Usage Table (page 32)](https://usb.org/sites/default/files/hut1_4.pdf)
* [Simulation Controls (page 61)](https://usb.org/sites/default/files/hut1_4.pdf)

## Device report descriptor example (usbd_hid.c)

```
  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
  0x09, 0x05, // 0x05 - USAGE (Gamepad), 0x04 - USAGE (Joystick)
  0xA1, 0x01, // COLLECTION (Application)

  // Usage Generic Desktop Pointer
  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
  0x09, 0x01, // USAGE (Pointer)
  0xA1, 0x00, // COLLECTION (Physical)
  0x09, 0xXX, // 0x30 - USAGE (X), 0x31 - USAGE (Y), 0x32 - USAGE (Z), 0x33 - USAGE (Rx), 0x34 - USAGE (Ry), 0x35 - USAGE (Rz), 0x40 - USAGE (Vx), 0x41 - USAGE (Vy), 0x42 - USAGE (Vz), 0x43 - USAGE (Vbrx), 0x44 - USAGE (Vbry), 0x45 - USAGE (Vbrz), 0x45 - USAGE (Vno)
  // ... duplicate line above for each axis of a pointer unit
  0x15, 0x81, // Logical Minimum (-127)
  0x25, 0x7F, // Logical Maximum (127)
//  0x15, 0x00, // Logical Minimum (0)
//  0x26, 0x00, 0x10, // Logical Maximum (4096) 
  0x75, 0x08, // REPORT_SIZE (8)
//  0x75, 0x10, // REPORT_SIZE (16)
  0x95, 0x0x, // REPORT_COUNT (x) (axis count)
  0x81, 0x02, // INPUT (Data,Var,Abs)
  0xC0, // END_COLLECTION

  // Usage Simulation Controls
  0x05, 0x02, // USAGE_PAGE (Simulation Controls)
  0x09, 0xXX, // 0xc5 - Brake, 0xc6 - Clutch, 0xc7 - Shifter ... (Please refer to Simulation Controls Page for the full list)
  0x15, 0x00, // LOGICAL_MINIMUM (0)
  0x26, 0x00, 0x10, // LOGICAL_MAXIMUM (4096)
  0x75, 0x10, // REPORT_SIZE (16)
  0x95, 0x01, // REPORT_COUNT (1)
  0x81, 0x02, // INPUT (Data,Var,Abs)

  // Usage Buttons
  0x05, 0x09, // USAGE_PAGE (Button)
  0x19, 0x01, // USAGE_MINIMUM (Button 1)
  0x29, 0xXX, // USAGE_MAXIMUM (Button x) (buttons count)
  0x15, 0x00, // LOGICAL_MINIMUM (0)
  0x25, 0x01, // LOGICAL_MAXIMUM (1)
  0x75, 0x01, // REPORT_SIZE (1)
  0x95, 0xXX, // REPORT_COUNT (x) (buttons count)
  0x81, 0x02, // INPUT (Data,Var,Abs)
  0x95, 0xXX, // REPORT_COUNT (n) (remaining bits alignment: the number of bytes to accommodate the number of buttons multiplied by 8, minus the number of buttons)
  0x81, 0x03, // INPUT (Constant,Var,Abs)

  // end COLLECTION (Application)
  0xC0, // END_COLLECTION
```
