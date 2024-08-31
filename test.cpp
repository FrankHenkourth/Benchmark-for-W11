#include <iostream>
#include <chrono>
#include <cmath>
#include <lua.hpp>

using namespace std;

//misma test_cpu...
double cpuTest() {
    auto start = chrono::high_resolution_clock::now();

    volatile double result = 0.0;
    for (long long i = 0; i < 1e8; ++i) {
        result += sin(i) * cos(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    return duration.count();
}


double runLuaTest(const std::string& scriptPath) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, scriptPath.c_str()) != LUA_OK) {
        cerr << "Error al ejecutar el script Lua: " << lua_tostring(L, -1)<<endl;
        lua_pop(L, 1);
        lua_close(L);
        return -1.0;
    }

    lua_getglobal(L, "elapsedTime");
    double gpuTime = lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_close(L);
    return gpuTime;
}

double puntuacion(double cpuTime, double gpuTime) {
    if (gpuTime <= 0) return -1.0;
    double score = (cpuTime + gpuTime) / 2.0;
    return 100.0 / score;
}

int main() {
    double cpuTime = cpuTest();
    cout << "Tiempo de prueba de CPU: " << cpuTime << " segundos" <<endl;

    double gpuTime = runLuaTest("gpu_test.lua");
    if (gpuTime < 0) {
        cerr << "La prueba de GPU falló." << endl;
        return 1;
    }
    cout << "Tiempo de prueba de GPU: " <<gpuTime<< " segundos" << ndl;

    double score = puntuacion(cpuTime, gpuTime);
    cout << "Puntuación total: " <<score<<endl;

    return 0;
}
