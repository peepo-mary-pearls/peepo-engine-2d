#ifndef SPRITE_H
#define SPRITE_H
#include "gameObject.h"
#include "transform.h"

struct sprite{
    SDL_Texture* texture;
    SDL_Surface* surf;
    SDL_Renderer* game_renderer;
    SDL_Rect dst_rect;
    SDL_Rect src_rect;
    transform* transform;
    int frames;
    int curr_frame;
    float animationSpeed;
    float __animationTimer;
};typedef struct sprite sprite;

void sprite_new(component* comp, const char* path, int w, int h);
void sprite_new_animated(component* comp, const char* path, int frames, float animationSpeed);
void sprite_destroy(sprite* r);
void sprite_init();
void sprite_update(component* c);

#endif