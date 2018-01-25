/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  main.cpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "PathTracer.hpp"
#include "RayTracer.hpp"
#include "Random.hpp"
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, const char * argv[])
    {
    PathTracer::render (128, 128, 8);
    return 0;
    }