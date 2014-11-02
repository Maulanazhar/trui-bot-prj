#include <arduino/Arduino.h>
#include <arduino/Wire.h>
#include <comm/custom.h>
#include <comm/arduino_mavlink_packet_handler.hpp>


// void isr() {
//   const uint8_t channel1= MAVLINK_COMM_1;
//   const uint8_t channel2= MAVLINK_COMM_2;
//   const uint8_t channel3= MAVLINK_COMM_3;
//   const uint8_t desired_msgid= MAVLINK_MSG_ID_MANUAL_SETPOINT;

//   mavlink_message_t rx_msg1;
//   mavlink_status_t rx_status1;

//   mavlink_message_t rx_msg2;
//   mavlink_status_t rx_status2;

//   mavlink_message_t rx_msg3;
//   mavlink_status_t rx_status3;

//   //6A. 1. Send next speed command to all motors, :stop

//   float slave1_cmd_speed= 0.;
//   float slave2_cmd_speed= 0.;
//   float slave3_cmd_speed= 0.;

//   mavlink_message_t msg_to_slave1;
//   mavlink_message_t msg_to_slave2;
//   mavlink_message_t msg_to_slave3;
//   uint8_t system_id= MAV_TYPE_RBMT;
//   uint8_t component_id= MAV_COMP_ID_ARDUINO_MASTER;
    
//   uint32_t time_boot_ms= millis(); 
//   mavlink_msg_manual_setpoint_pack(system_id, component_id, &msg_to_slave1, time_boot_ms, slave1_cmd_speed, 0., 0., 0., 0, 0);
//   mavlink_msg_manual_setpoint_pack(system_id, component_id, &msg_to_slave2, time_boot_ms, slave2_cmd_speed, 0., 0., 0., 0, 0);
//   mavlink_msg_manual_setpoint_pack(system_id, component_id, &msg_to_slave3, time_boot_ms, slave3_cmd_speed, 0., 0., 0., 0, 0);

//   uint8_t buf1[MAVLINK_MAX_PACKET_LEN];
//   uint8_t buf2[MAVLINK_MAX_PACKET_LEN];
//   uint8_t buf3[MAVLINK_MAX_PACKET_LEN];
//   uint16_t len1 = mavlink_msg_to_send_buffer(buf1, &msg_to_slave1);    
//   uint16_t len2 = mavlink_msg_to_send_buffer(buf2, &msg_to_slave2);    
//   uint16_t len3 = mavlink_msg_to_send_buffer(buf3, &msg_to_slave3);
    
//   Serial1.write(buf1, len1);    
//   Serial2.write(buf2, len2); 
//   Serial3.write(buf3, len3);     
    
//   //6B. Query actual speed for each motor for past cmd_speed
//   time_boot_ms= millis(); 
//   mavlink_msg_command_int_pack(system_id, component_id, &msg_to_slave1, 0, 0, 0, 0, 0, 0, 0., 0., 0., 0., 0, 0, 0.);
//   len1 = mavlink_msg_to_send_buffer(buf1, &msg_to_slave1); 
//   Serial1.write(buf1, len1);
//   while (true) {
//     if (Serial1.available() > 0) {
//       if (mavlink_parse_char(channel1, Serial1.read(), &rx_msg1, &rx_status1)) {
//         if ( (rx_msg1.msgid==desired_msgid) ) {
//           break;
//         }
//       }
//     }
//   }

//   time_boot_ms= millis(); 
//   mavlink_msg_command_int_pack(system_id, component_id, &msg_to_slave2, 0, 0, 0, 0, 0, 0, 0., 0., 0., 0., 0, 0, 0.);
//   len2 = mavlink_msg_to_send_buffer(buf2, &msg_to_slave2); 
//   Serial2.write(buf2, len2);
//   while (true) {
//     if (Serial2.available() > 0) {
//       if (mavlink_parse_char(channel2, Serial2.read(), &rx_msg2, &rx_status2)) {
//         if ( (rx_msg2.msgid==desired_msgid) ) {
//           break;
//         }
//       }
//     }
//   }

//   time_boot_ms= millis(); 
//   mavlink_msg_command_int_pack(system_id, component_id, &msg_to_slave3, 0, 0, 0, 0, 0, 0, 0., 0., 0., 0., 0, 0, 0.);
//   len3 = mavlink_msg_to_send_buffer(buf3, &msg_to_slave3); 
//   Serial3.write(buf3, len3);
//   while (true) {
//     if (Serial3.available() > 0) {
//       if (mavlink_parse_char(channel3, Serial3.read(), &rx_msg3, &rx_status3)) {
//         if ( (rx_msg3.msgid==desired_msgid) ) {
//           break;
//         }
//       }
//     }
//   }

//   mavlink_manual_setpoint_t msg;

//   mavlink_msg_manual_setpoint_decode(&rx_msg1, &msg);
//   float slave1_actual_speed= msg.roll;
//   mavlink_msg_manual_setpoint_decode(&rx_msg2, &msg);
//   float slave2_actual_speed= msg.roll;
//   mavlink_msg_manual_setpoint_decode(&rx_msg3, &msg);
//   float slave3_actual_speed= msg.roll;

//   //6C. Send actual speed to PC controller
//   mavlink_message_t msg_to_controller;
  
//   time_boot_ms= millis(); 
//   mavlink_msg_set_position_target_local_ned_pack(system_id, component_id, &msg_to_controller, 
//     time_boot_ms, 0, 0, 0, 0, 0., 0., 0., slave1_actual_speed, slave2_actual_speed, slave3_actual_speed, 0., 0., 0., 0., 0.);
//   uint8_t buf[MAVLINK_MAX_PACKET_LEN];
//   uint16_t len = mavlink_msg_to_send_buffer(buf, &msg_to_controller); 
//   Serial.write(buf, len);
// }

int main() {
  init();
  Serial.begin(57600);
  Serial1.begin(9600);
  Serial2.begin(9600);    
  Serial3.begin(9600);
  //Wire.begin();

  const uint8_t header= 0xCE;
  const uint8_t footer= 0xEE;

  const uint8_t hit_mode= 0x0A;
  const uint8_t position_mode= 0x0B;
  const uint8_t hit_flag= 0x0F;

  const uint8_t channel= MAVLINK_COMM_0;
  const uint8_t desired_msgid= MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED;    

  mavlink_message_t rx_msg;
  mavlink_status_t rx_status;  
 long timeNow = 0, timeOld = 0;
      bool ctr = 0;
  // motor.testing_encoder();
    int slave1_cmd_speed=50;//;= 50;//msg.vx;               
    int slave2_cmd_speed=0;//= 50;//msg.vy;
    int slave3_cmd_speed=0;//= 50;//msg.vz;
  while (true) {
    
    //1. wait for cmd_speed from serial from controller
    // while (true) {
    //   if (Serial.available() > 0) {
    //     if (mavlink_parse_char(channel, Serial.read(), &rx_msg, &rx_status)) {
    //       if ( (rx_msg.msgid==desired_msgid) ) {
    //         break;
    //       }
    //     }
    //   }
    // }

    // //2. break down the speed into the speed for 3 motors
    // mavlink_set_position_target_local_ned_t msg;
    // mavlink_msg_set_position_target_local_ned_decode(&rx_msg, &msg);




    
     
    
    uint8_t buffer1[7];
    uint8_t buffer2[7];
    uint8_t buffer3[7];


    timeNow = millis();
    if(timeNow - timeOld >= 2000){
      timeOld = timeNow;
      if(ctr == 1) {slave1_cmd_speed = 100;ctr = 0;buffer1[3]= 0xCC;}
      else if(ctr ==0) {slave1_cmd_speed = -100;ctr = 1;buffer1[3]= 0x0C;}
      
    }  


    // if(slave1_cmd_speed < 0)  buffer1[3]= 0x0C;
    //   else if (slave1_cmd_speed >= 0)  buffer1[3]= 0xCC;

    // if(slave2_cmd_speed < 0)  buffer2[3]= 0x0C;
    //   else if (slave2_cmd_speed >= 0)  buffer2[3]= 0xCC;

    // if(slave3_cmd_speed < 0)  buffer3[3]= 0x0C;
    //   else if (slave3_cmd_speed >= 0)  buffer3[3]= 0xCC;


    slave1_cmd_speed = abs(slave1_cmd_speed);
    slave2_cmd_speed = abs(slave2_cmd_speed);
    slave3_cmd_speed = abs(slave3_cmd_speed);

    //3. dispatch and send the 3 speed values
    
    buffer1[0]= header;
    buffer1[6]= footer;
    buffer1[2]= (int) ((slave1_cmd_speed & 0xFF00) >> 8);
    buffer1[1]= (int) ((slave1_cmd_speed & 0x00FF));

    uint16_t checksum1= buffer1[0] + buffer1[1] + buffer1[2] + buffer1[3] + buffer1[4] + buffer1[8];
    buffer1[4]= (int) ((checksum1 & 0x00FF));
    buffer1[5]= (int) ((checksum1 & 0xFF00) >> 8);


    
    buffer2[0]= header;
    buffer2[6]= footer;
    buffer2[2]= (int) ((slave2_cmd_speed & 0x0000FF00) >> 8);
    buffer2[1]= (int) ((slave2_cmd_speed & 0x000000FF));

    uint16_t checksum2= buffer2[0] + buffer2[1] + buffer2[2] + buffer2[3] + buffer2[4] + buffer2[8];
    buffer2[4]= (int) ((checksum2 & 0x00FF));
    buffer2[5]= (int) ((checksum2 & 0xFF00) >> 8);

    buffer3[0]= header;
    buffer3[6]= footer;
    buffer3[2]= (int) ((slave3_cmd_speed & 0x0000FF00) >> 8);
    buffer3[1]= (int) ((slave3_cmd_speed & 0x000000FF));

    uint16_t checksum3= buffer3[0] + buffer3[1] + buffer3[2] + buffer3[3] + buffer3[4] + buffer3[8];
    buffer3[4]= (int) ((checksum3 & 0x00FF));
    buffer3[5]= (int) ((checksum3 & 0xFF00) >> 8);
    
    //Serial.println(buffer1[0]);
     Serial.print("buffer1 ");Serial.println(buffer1[1]);
    // Serial.print("buffer2 ");Serial.println(buffer1[2]);
     Serial.println(ctr);
     Serial.println(buffer1[3]);
    // //Serial.println(buffer1[4]);
    // //Serial.println(buffer1[5]);
    // //Serial.println(buffer1[6]);
    // Serial.println((buffer1[1] | (buffer1[2]<<8)));
    Serial1.write(buffer1, 7);
    Serial2.write(buffer2, 7);
    Serial3.write(buffer3, 7);

    //hit-manipulation slave
    int8_t slave_hit1_speed;
    int8_t slave_hit2_speed;
    int target_pos1;
    int target_pos2;
    uint8_t buffer_hit1[11];
    uint8_t buffer_hit2[11];

    buffer_hit1[0]= header;
    buffer_hit1[10]= footer;
    buffer_hit1[1]= hit_mode;
    buffer_hit1[2]= hit_flag;
    buffer_hit1[6]= (int) ((slave_hit1_speed & 0xFF000000) >> 24);
    buffer_hit1[5]= (int) ((slave_hit1_speed & 0x00FF0000) >> 16);
    buffer_hit1[4]= (int) ((slave_hit1_speed & 0x0000FF00) >> 8);
    buffer_hit1[3]= (int) ((slave_hit1_speed & 0x000000FF));
    buffer_hit1[7]= target_pos1;
    uint16_t checksum_hit1= buffer_hit1[0] + buffer_hit1[1] + buffer_hit1[2] + buffer_hit1[3] + buffer_hit1[4] + buffer_hit1[5] + buffer_hit1[6] + buffer_hit1[7] + buffer_hit1[10];
    buffer_hit1[8]= (int) ((checksum_hit1 & 0x00FF));
    buffer_hit1[9]= (int) ((checksum_hit1 & 0xFF00));
    
    buffer_hit2[0]= header;
    buffer_hit2[10]= footer;
    buffer_hit2[1]= hit_mode;
    buffer_hit2[2]= hit_flag;
    buffer_hit2[6]= (int) ((slave_hit2_speed & 0xFF000000) >> 24);
    buffer_hit2[5]= (int) ((slave_hit2_speed & 0x00FF0000) >> 16);
    buffer_hit2[4]= (int) ((slave_hit2_speed & 0x0000FF00) >> 8);
    buffer_hit2[3]= (int) ((slave_hit2_speed & 0x000000FF));
    buffer_hit2[7]= target_pos2;
    uint16_t checksum_hit2= buffer_hit2[0] + buffer_hit2[1] + buffer_hit2[2] + buffer_hit2[3] + buffer_hit2[4] + buffer_hit2[5] + buffer_hit2[6] + buffer_hit2[7] + buffer_hit2[10];
    buffer_hit2[8]= (int) ((checksum_hit2 & 0x00FF));
    buffer_hit2[9]= (int) ((checksum_hit2 & 0xFF00));

    Wire.beginTransmission(0x15);
    Wire.write(buffer_hit1, 11);
    Wire.endTransmission();

    Wire.beginTransmission(0x09);
    Wire.write(buffer_hit2, 11);
    Wire.endTransmission();
    //4. activate timer according to dt using timer overflow interrupt
    //activateTimer();

    //5. back to 1
    //6. if timer overflow interrupt happens, do 6A

  }

  return 0;
}

