#include "skin.h"

#include <raylib.h>

static Texture2D        skin_elements[num_skin_elements];
static Sound            hit_sounds[num_hit_sounds];

void load_skin()
{
        // load all the skin elements and hitsounds needed
        skin_elements[APPROACH_CIRCLE] = LoadTexture(ASSET_PATH
                "/approachcircle.png");
        skin_elements[HIT_CIRCLE] = LoadTexture(ASSET_PATH
                "/hitcircle.png");
        skin_elements[HIT_CIRCLE_OVERLAY] = LoadTexture(ASSET_PATH
                "/hitcircleoverlay.png");
        skin_elements[SLIDER_END_CIRCLE] = LoadTexture(ASSET_PATH
                "/sliderendcircle.png");
        skin_elements[SLIDER_FOLLOW_CIRCLE] = LoadTexture(ASSET_PATH
                "/sliderfollowcircle.png");
        skin_elements[SLIDER_BALL] = LoadTexture(ASSET_PATH
                "/sliderball0.png");
        skin_elements[SLIDER_SCORE_POINT] = LoadTexture(ASSET_PATH
                "/sliderscorepoint.png");
        skin_elements[REVERSE_ARROW] = LoadTexture(ASSET_PATH
                "/reversearrow.png");

        skin_elements[COMBO_0] = LoadTexture(ASSET_PATH "/combo-0.png");
        skin_elements[COMBO_1] = LoadTexture(ASSET_PATH "/combo-1.png");
        skin_elements[COMBO_2] = LoadTexture(ASSET_PATH "/combo-2.png");
        skin_elements[COMBO_3] = LoadTexture(ASSET_PATH "/combo-3.png");
        skin_elements[COMBO_4] = LoadTexture(ASSET_PATH "/combo-4.png");
        skin_elements[COMBO_5] = LoadTexture(ASSET_PATH "/combo-5.png");
        skin_elements[COMBO_5] = LoadTexture(ASSET_PATH "/combo-6.png");
        skin_elements[COMBO_7] = LoadTexture(ASSET_PATH "/combo-7.png");
        skin_elements[COMBO_8] = LoadTexture(ASSET_PATH "/combo-8.png");
        skin_elements[COMBO_9] = LoadTexture(ASSET_PATH "/combo-9.png");

        // drum set
        hit_sounds[DRUM_HIT_NORMAL] = LoadSound(ASSET_PATH
                "/drum-hitnormal.wav");
        hit_sounds[DRUM_HIT_CLAP] = LoadSound(ASSET_PATH
                "/drum-hitclap.wav");
        hit_sounds[DRUM_HIT_FINISH] = LoadSound(ASSET_PATH
                "/drum-hitfinish.wav");
        hit_sounds[DRUM_HIT_WHISTLE] = LoadSound(ASSET_PATH
                "/drum-hitwhistle.wav");
        hit_sounds[DRUM_SLIDER_TICK] = LoadSound(ASSET_PATH
                "/drum-slidertick.wav");
        hit_sounds[DRUM_SLIDER_SLIDE] = LoadSound(ASSET_PATH
                "/drum-sliderslide.wav");
        hit_sounds[DRUM_SLIDER_WHISTLE] = LoadSound(ASSET_PATH
                "/drum-sliderwhistle.wav");
        // normal set
        hit_sounds[NORMAL_HIT_NORMAL] = LoadSound(ASSET_PATH
                "/normal-hitnormal.wav");
        hit_sounds[NORMAL_HIT_CLAP] = LoadSound(ASSET_PATH
                "/normal-hitclap.wav");
        hit_sounds[NORMAL_HIT_FINISH] = LoadSound(ASSET_PATH
                "/normal-hitfinish.wav");
        hit_sounds[NORMAL_HIT_WHISTLE] = LoadSound(ASSET_PATH
                "/normal-hitwhistle.wav");
        hit_sounds[NORMAL_SLIDER_TICK] = LoadSound(ASSET_PATH
                "/normal-slidertick.wav");
        hit_sounds[NORMAL_SLIDER_SLIDE] = LoadSound(ASSET_PATH
                "/normal-sliderslide.wav");
        hit_sounds[NORMAL_SLIDER_WHISTLE] = LoadSound(ASSET_PATH
                "/normal-sliderwhistle.wav");
        // soft set
        hit_sounds[SOFT_HIT_NORMAL] = LoadSound(ASSET_PATH
                "/soft-hitnormal.wav");
        hit_sounds[SOFT_HIT_CLAP] = LoadSound(ASSET_PATH
                "/soft-hitclap.wav");
        hit_sounds[SOFT_HIT_FINISH] = LoadSound(ASSET_PATH
                "/soft-hitfinish.wav");
        hit_sounds[SOFT_HIT_WHISTLE] = LoadSound(ASSET_PATH
                "/soft-hitwhistle.wav");
        hit_sounds[SOFT_SLIDER_TICK] = LoadSound(ASSET_PATH
                "/soft-slidertick.wav");
        hit_sounds[SOFT_SLIDER_SLIDE] = LoadSound(ASSET_PATH
                "/soft-sliderslide.wav");
        hit_sounds[SOFT_SLIDER_WHISTLE] = LoadSound(ASSET_PATH
                "/soft-sliderwhistle.wav");
}

void draw_element(int x, int y, enum skin_element element_type)
{
	DrawTexture(skin_elements[element_type], x, y, WHITE);
}

void play_sound(enum hit_sound sound_type)
{
	PlaySound(hit_sounds[sound_type]);
}
