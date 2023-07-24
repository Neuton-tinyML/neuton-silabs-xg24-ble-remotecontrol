#define KEY_MEDIA_VOLUMEUP      (1     )  // Keyboard Media Button VolumeUp
#define KEY_MEDIA_VOLUMEDOWN    (1 << 1)  // Keyboard Media Button VolumeDown
#define KEY_MEDIA_MUTE          (1 << 2)  // Keyboard Media Button Mute
#define KEY_MEDIA_PLAYPAUSE     (1 << 3)  // Keyboard Media Button Play/Pause
#define KEY_MEDIA_NEXT_TRACK    (1 << 4)  // Keyboard Media Button Next
#define KEY_MEDIA_PREV_TRACK    (1 << 5)  // Keyboard Media Button Previous  

#define KEY_ARROW_UP 0x52 // Keyboard Up Arrow
#define KEY_ARROW_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ARROW_LEFT 0x50 // Keyboard Left Arrow
#define KEY_ARROW_RIGHT 0x4f // Keyboard Right Arrow

#define KEY_F5 0x3e // Keyboard F5
#define KEY_ESC 0x29 // Keyboard ESCAPE

#define REPORT_PAGE_KEYBOARD 0x01
#define REPORT_PAGE_MEDIA 0x02

#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"

extern uint8_t current_report_page;
extern uint8_t current_key;
extern uint8_t current_modifier_key;
#ifdef __cplusplus
extern "C" {
#endif
void sl_bt_reset_report(void);
bool sl_bt_is_connected(void);
#ifdef __cplusplus
}
#endif
