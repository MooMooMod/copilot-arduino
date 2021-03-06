// Using an MPU6050
// Calculate angle that the IMU is facing

// Wire library is required for I2C
#include <Wire.h>
#include <SPI.h>

const int MPU6050_ADDRESS = 0x68;
const int MPU6050_RA_ACCEL_XOUT_H = 0x3B;
const int MPU6050_RA_GYRO_XOUT_H = 0x43;
const int MPU6050_RA_PWR_MGMT_1 = 0x6B;
const int MPU6050_PWR1_CLKSEL_BIT = 2;
const int MPU6050_PWR1_CLKSEL_LENGTH = 3;
const int MPU6050_CLOCK_PLL_XGYRO = 0x01;
const int MPU6050_RA_WHO_AM_I = 0x75;
const int MPU6050_RA_GYRO_CONFIG = 0x1B;
const int MPU6050_GCONFIG_FS_SEL_BIT = 4;
const int MPU6050_GCONFIG_FS_SEL_LENGTH = 2;
const int MPU6050_GYRO_FS_250 = 0x00;
const int MPU6050_GYRO_FS_500 = 0x01;
const int MPU6050_GYRO_FS_1000 = 0x02;
const int MPU6050_GYRO_FS_2000 = 0x03;
const int MPU6050_RA_ACCEL_CONFIG = 0x1C;
const int MPU6050_ACONFIG_AFS_SEL_BIT = 4;
const int MPU6050_ACONFIG_AFS_SEL_LENGTH = 2;
const int MPU6050_ACCEL_FS_2 = 0x00;
const int MPU6050_ACCEL_FS_4 = 0x01;
const int MPU6050_ACCEL_FS_8 = 0x02;
const int MPU6050_ACCEL_FS_16 = 0x03;

void setupIMU()
{
    Wire.begin();
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(MPU6050_RA_PWR_MGMT_1);
    Wire.write(0);
    Wire.endTransmission(true);
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(MPU6050_RA_GYRO_CONFIG);
    Wire.write(MPU6050_GYRO_FS_500 << MPU6050_GCONFIG_FS_SEL_BIT);
    Wire.endTransmission(true);
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(MPU6050_RA_ACCEL_CONFIG);
    Wire.write(MPU6050_ACCEL_FS_2 << MPU6050_ACONFIG_AFS_SEL_BIT);
    Wire.endTransmission(true);
}

void printIMU()
{
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(MPU6050_RA_ACCEL_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050_ADDRESS, 6, true);
    int16_t ax = Wire.read() << 8 | Wire.read();
    int16_t ay = Wire.read() << 8 | Wire.read();
    int16_t az = Wire.read() << 8 | Wire.read();
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(MPU6050_RA_GYRO_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050_ADDRESS, 6, true);
    int16_t gx = Wire.read() << 8 | Wire.read();
    int16_t gy = Wire.read() << 8 | Wire.read();
    int16_t gz = Wire.read() << 8 | Wire.read();
    Serial.print(ax);
    Serial.print(" ");
    Serial.print(ay);
    Serial.print(" ");
    Serial.print(az);
    Serial.print(" ");
    Serial.print(gx);
    Serial.print(" ");
    Serial.print(gy);
    Serial.print(" ");
    Serial.print(gz);
    Serial.print(" ");
    Serial.println();
    delay(100);
}
