#include "p11_test.h"
#include "../vm/luagc.h"
#include "../common/luastring.h"

static void check_error(struct lua_State* L, int code) {
	if (code != LUA_OK) {
		TString* ts = gco2ts(gcvalue(L->top - 1));
		printf(getstr(ts));
	}
}

void p11_test_main() {
	struct lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int ok = luaL_loadfile(L, "./scripts/part11_test.lua");
	check_error(L, ok);

	ok = luaL_pcall(L, 0, 0);
	check_error(L, ok);

	luaL_close(L);
}
