// *********     Read and Write Example      *********
//
//
// Available Dynamixel model on this example : All models using Protocol 2.0
// This example is tested with a Dynamixel PRO 54-200, and an USB2DYNAMIXEL
//현재 사용 다이나믹셀 : ID -> 1 // Baudrate -> 1000000)
//

#include <DynamixelSDK.h>


// Control table address
#define ADDR_PRO_TORQUE_ENABLE          562                 // Control table address is different in Dynamixel model
#define ADDR_PRO_GOAL_POSITION          4094
#define ADDR_PRO_PRESENT_POSITION       0

// Protocol version
#define PROTOCOL_VERSION                2.0                 // See which protocol version is used in the Dynamixel

// Default setting
#define DXL_ID                          1                   // Dynamixel ID: 1
#define BAUDRATE                        1000000
#define DEVICENAME                      "OpenCR_DXL_Port"   // This definition only has a symbolic meaning and does not affect to any functionality

#define TORQUE_ENABLE                   1                   // Value for enabling the torque
#define TORQUE_DISABLE                  0                   // Value for disabling the torque
#define DXL_MINIMUM_POSITION_VALUE      -256              // Dynamixel will rotate between this value
#define DXL_MAXIMUM_POSITION_VALUE      256              // and this value (note that the Dynamixel would not move when the position value is out of movable range. Check e-manual about the range of the Dynamixel you use.)
#define DXL_MOVING_STATUS_THRESHOLD     20                  // Dynamixel moving status threshold

#define ESC_ASCII_VALUE                 0x1b

#define CMD_SERIAL                      Serial

int getch()
{
  while(1)
  {
    if( CMD_SERIAL.available() > 0 )
    {
      break;
    }
  }

  return CMD_SERIAL.read();
}

int kbhit(void)
{
  return CMD_SERIAL.available();
}

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  Serial.println("Start..");

  // Initialize PortHandler instance
  // Set the port path
  // Get methods and members of PortHandlerLinux or PortHandlerWindows
  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);

  // Initialize PacketHandler instance
  // Set the protocol version
  // Get methods and members of Protocol1PacketHandler or Protocol2PacketHandler
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

  int index = 0;
  int dxl_comm_result = COMM_TX_FAIL;             // Communication result
  int dxl_goal_position[2] = {DXL_MINIMUM_POSITION_VALUE, DXL_MAXIMUM_POSITION_VALUE};         // Goal position

  uint8_t dxl_error = 0;                          // Dynamixel error
  int32_t dxl_present_position = 0;               // Present position

  // Open port
  if (portHandler->openPort())
  {
    Serial.print("Succeeded to open the port!\n");
  }
  else
  {
    Serial.print("Failed to open the port!\n");
    return;
  }

  // Set port baudrate
  if (portHandler->setBaudRate(BAUDRATE))
  {
    Serial.print("Succeeded to change the baudrate!\n");
  }
  else
  {
    Serial.print("Failed to change the baudrate!\n");
    return;
  }

  // Enable Dynamixel Torque
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    Serial.print(packetHandler->getTxRxResult(dxl_comm_result));
  }
  else if (dxl_error != 0)
  {
    Serial.print(packetHandler->getRxPacketError(dxl_error));
  }
  else
  {
    Serial.print("Dynamixel has been successfully connected \n");
  }

  while(1)
  {
    Serial.print("Press any key to continue! (or press q to quit!)\n");
    if (getch() == 'q')
      break;

    // Write goal position
    dxl_comm_result = packetHandler->write4ByteTxRx(portHandler, DXL_ID, ADDR_PRO_GOAL_POSITION, dxl_goal_position[index], &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
      Serial.print(packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
      Serial.print(packetHandler->getRxPacketError(dxl_error));
    }

    do
    {
      // Read present position
      dxl_comm_result = packetHandler->read4ByteTxRx(portHandler, DXL_ID, ADDR_PRO_PRESENT_POSITION, (uint32_t*)&dxl_present_position, &dxl_error);
      if (dxl_comm_result != COMM_SUCCESS)
      {
        Serial.print(packetHandler->getTxRxResult(dxl_comm_result));
      }
      else if (dxl_error != 0)
      {
        Serial.print(packetHandler->getRxPacketError(dxl_error));
      }

      Serial.print("[ID:"); Serial.print(DXL_ID);
      Serial.print("] GoalPos:"); Serial.print(dxl_goal_position[index]);
      Serial.print("  PresPos:"); Serial.print(dxl_present_position);
      Serial.println(" ");

    }while((abs(dxl_goal_position[index] - dxl_present_position) > DXL_MOVING_STATUS_THRESHOLD));

    // Change goal position
    if (index == 0)
    {
      index = 1;
    }
    else
    {
      index = 0;
    }
  }

  // Disable Dynamixel Torque
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_PRO_TORQUE_ENABLE, TORQUE_DISABLE, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    Serial.print(packetHandler->getTxRxResult(dxl_comm_result));
  }
  else if (dxl_error != 0)
  {
    Serial.print(packetHandler->getRxPacketError(dxl_error));
  }

  // Close port
  portHandler->closePort();
}

void loop()
{
}
