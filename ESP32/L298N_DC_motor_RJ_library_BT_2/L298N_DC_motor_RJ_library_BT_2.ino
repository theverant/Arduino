/*
   INSTALL MOTOR CONTROL LIBRARY FROM HERE: http://robojax.com/node/1096
   INSTALL PS3 LIBRARY FROM ARDUINO IDE

   Written by Ahmad Shamshiri on Dec 24, 2019
   in Ajax, Ontario, Canada. www.robojax.com

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>

 Bashed together with Ps3Controller library by Theverant.

 Motor moves CW with Triangle button press, stops on release.  CCW with cross, stops on release.

*/

#include <Robojax_L298N_DC_motor.h>
#include <Ps3Controller.h>

// motor 1 settings

#define ENA 19 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 18
#define IN2 5

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change

//Robojax_L298N_DC_motor motor(IN1, IN2, ENA);
// Watch video instruciton for this line: https://youtu.be/2JTMqURJTwg
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, true);



void setup() {
  Serial.begin(115200);
  motor.begin();   //L298N DC Motor by Robojax.com
  Ps3.begin("cc:50:e3:96:32:f6");  // change this with your own ESP BT MAC Adress.  Use tool on PC to write YOUR MAC address to YOUR sixaxis controller
  Serial.println("Ready.");


}

void loop() {

  if (Ps3.isConnected()) {


    if ( Ps3.data.button.triangle ) {
      Serial.println("Turning motor 1 CW");
      motor.rotate(motor1, 60, CW);//run motor1 at 60% speed in CW direction
    } else if ( Ps3.data.button.cross ) {
      Serial.println("Pressing the cross button");
       motor.rotate(motor1, 60, CCW);//run motor1 at 60% speed in CW direction
    } else {
      motor.brake(1);
    }

    delay(20);

  }
}
