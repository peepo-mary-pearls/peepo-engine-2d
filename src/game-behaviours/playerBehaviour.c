#include "components.h"

void player_new(gameObject* go, float speed, float shootCooldown, int maxHealth){
    playerBehaviour* p = (playerBehaviour*)malloc(sizeof(playerBehaviour));
    component* c = __component_new(go);
    p->__speed = speed;
    p->__shootCD = shootCooldown;
    p->__maxHealth = maxHealth;
    p->__currHealth = maxHealth;
    p->__bullets = vector_new_with_cap(20);
    c->data = p;
    c->init = player_init;
    c->update = player_update;
    c->destroy = player_destroy;
    c->on_enable = player_on_enable;
    c->on_disable = player_on_disable;
    c->type = PLAYER_T;
}

void player_init(component* comp){

}

void player_update(component* c){
    const Uint8* state = SDL_GetKeyboardState(NULL);
    transform* t = (transform*)gameObject_get_component(c->owner, TRANSFORM_T);
    playerBehaviour* p = (playerBehaviour*)gameObject_get_component(c->owner, PLAYER_T);
    sprite* s = (sprite*)gameObject_get_component(c->owner, SPRITE_T);
    float dt = delta_time(c->owner->__scene);
    if(state[SDL_SCANCODE_LEFT]){
        if((int)t->pos.x > 0) //avoid exit from screen x < 0
            t->pos.x -= 1.f * p->__speed * dt;
    }
    if(state[SDL_SCANCODE_RIGHT]){
        if((int)t->pos.x < c->owner->__scene->__game->width - s->dst_rect.w) //avoid exit from screen x > window.w
            t->pos.x += 1.f * p->__speed * dt;
    }
    if(state[SDL_SCANCODE_UP]){
        if((int)t->pos.y > 0)
            t->pos.y -= 1.f * p->__speed * dt;
    }
    if(state[SDL_SCANCODE_DOWN]){
        if((int)t->pos.y + s->dst_rect.h < 405) //hard coded atm
            t->pos.y += 1.f * p->__speed * dt;
    }
    if(state[SDL_SCANCODE_SPACE] && gameObject_is_active(c->owner)){
        gameObject_set_active(c->owner, false);
    }
}

void player_destroy(component* comp){
    playerBehaviour* p = (playerBehaviour*)comp->data;
    free(p); 
}

void player_on_enable(component* comp){

}

void player_on_disable(component* comp){

}