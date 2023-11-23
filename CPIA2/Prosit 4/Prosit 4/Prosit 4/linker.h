#pragma once

#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <thread>
#include <string>
#include <mutex>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

#include "receiver.h"
#include "emetter.h"
#include "threads.h"
#include "connections.h"