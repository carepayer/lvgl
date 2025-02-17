#include "../../lv_examples.h"
#if LV_USE_CANVAS && LV_BUILD_EXAMPLES && 0

#define CANVAS_WIDTH  50
#define CANVAS_HEIGHT  50

/**
 * Create a transparent canvas with Chroma keying and indexed color format (palette).
 */
void lv_example_canvas_2(void)
{
    /*Create a button to better see the transparency*/
    lv_btn_create(lv_scr_act());

    /*Create a buffer for the canvas*/
    static uint8_t cbuf[LV_CANVAS_BUF_SIZE_INDEXED_1BIT(CANVAS_WIDTH, CANVAS_HEIGHT)];

    /*Create a canvas and initialize its palette*/
    lv_obj_t * canvas = lv_canvas_create(lv_scr_act());
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_COLOR_FORMAT_I1);
    lv_canvas_set_palette(canvas, 0, lv_color_to32(LV_COLOR_CHROMA_KEY));
    lv_canvas_set_palette(canvas, 1, lv_color_to32(lv_palette_main(LV_PALETTE_RED)));

    /*Create colors with the indices of the palette*/
    lv_color_t c0;
    lv_color_t c1;

    lv_color_set_int(&c0, 0);
    lv_color_set_int(&c1, 1);

    /*Red background (There is no dedicated alpha channel in indexed images so LV_OPA_COVER is ignored)*/
    lv_canvas_fill_bg(canvas, c1, LV_OPA_COVER);

    /*Create hole on the canvas*/
    uint32_t x;
    uint32_t y;
    for(y = 10; y < 30; y++) {
        for(x = 5; x < 20; x++) {
            lv_canvas_set_px(canvas, x, y, c0, LV_OPA_COVER);
        }
    }
}
#endif
