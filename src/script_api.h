#ifndef SCRIPT_API_H
#define SCRIPT_API_H

#include <lua.h>
#include <lua.hpp>

// Lua context
typedef struct {
    lua_State* L;
} lua_context;

// Create Lua context
lua_context lua_new_context() {
    lua_context ctx = { lua_newstate(luaL_openlib, NULL) };
    luaL_openlib(ctx.L, "math", mathlib, 0);
    return ctx;
}

// Execute Lua script
int lua_run_script(lua_context ctx, const char* script) {
    luaL_dostring(ctx.L, script);
    return lua_tostring(ctx.L, -1) != NULL;
}

#endif // SCRIPT_API_H