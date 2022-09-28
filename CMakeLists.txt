cmake_minimum_required(VERSION 3.0.0)

project(StandLight)

add_executable(${PROJECT_NAME} 
./source/main.cpp

./source/hw/Button/Button.cpp
./source/hw/Led/Led.cpp
./source/hw/Clock_Check/Clock_Check.cpp
./source/hw/LCD/LCD.cpp
./source/hw/I2C/I2C.cpp
./source/hw/DHT11/DHT11.cpp
./source/hw/UltraSonic/UltraSonic.cpp
./source/hw/PWM/PWM.cpp

./source/app/listener/Listener.cpp
./source/app/Controler/Controler.cpp

./source/app/View/View.cpp
./source/app/View/Clock_View/Clock_View.cpp
./source/app/View/TH_View/TH_View.cpp
./source/app/View/Sonic_View/Sonic_View.cpp
./source/app/View/Motor_View/Motor_View.cpp

./source/app/Service/Service.cpp
./source/app/Service/Clock_Service/Clock_Service.cpp
./source/app/Service/TH_Service/TH_Service.cpp
./source/app/Service/Sonic_Service/Sonic_Service.cpp
./source/app/Service/Motor_Service/Motor_Service.cpp

)

target_include_directories(${PROJECT_NAME} PUBLIC

./source/hw/Button
./source/hw/Led
./source/hw/Clock_Check
./source/hw/LCD
./source/hw/I2C
./source/hw/DHT11
./source/hw/UltraSonic
./source/hw/PWM

./source/app/listener
./source/app/Controler

./source/app/View
./source/app/View/Clock_View
./source/app/View/TH_View
./source/app/View/Sonic_View
./source/app/View/Motor_View

./source/app/Service
./source/app/Service/Clock_Service
./source/app/Service/TH_Service
./source/app/Service/Sonic_Service
./source/app/Service/Motor_Service

)

target_link_libraries(${PROJECT_NAME} PUBLIC

-lwiringPi

)

target_compile_options(${PROJECT_NAME} PUBLIC
-Wall
)