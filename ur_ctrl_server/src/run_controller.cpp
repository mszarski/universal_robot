
#include "ur_ctrl_server/ur_ctrl_shared.h"
#ifdef TCP_COM
#include "simple_message/socket/tcp_server.h"
typedef industrial::tcp_server::TcpServer SimpleServer;
#else
#include "simple_message/socket/udp_server.h"
typedef industrial::udp_server::UdpServer SimpleServer;
#endif

#ifdef HARDWARE_CONTROLLER
#include "ur_ctrl_server/ur_hardware_controller.h"
typedef ur::URHardwareController URController;
#endif

#ifdef TEST_CONTROLLER
#include "ur_ctrl_server/ur_test_controller.h"
typedef ur::URTestController URController;
#endif

#ifdef SIMULATION_CONTROLLER
#include "ur_ctrl_server/ur_sim_controller.h"
typedef ur::URSimController URController;
#endif

int main(int argc, char** argv)
{

  SimpleServer connection;
  connection.init(UR_COM_PORT);
  URController ur_ctrl(&connection);

  if(ur_ctrl.initRobot(argc, argv))
    return -1;
  ur_ctrl.controlLoop();

  return 0;
}
