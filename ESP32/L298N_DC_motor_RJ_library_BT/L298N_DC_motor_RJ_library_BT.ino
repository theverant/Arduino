/*
   Library Example for L298N Module to control DC motors

   This code is to control single motor. For two motor control, please open L298N_DC_2_Motors
   Watch video instructions for this code:  https://youtu.be/2JTMqURJTwg

   Written by Ahmad Shamshiri on Dec 24, 2019
   in Ajax, Ontario, Canada. www.robojax.com


    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
  Ps3.begin("cc:50:e3:96:32:f6");
  Serial.println("Ready.");


}

void loop() {

  if (Ps3.isConnected()) {


    if ( Ps3.data.button.triangle ) {
      Serial.println("Pressing the triangle button");
      motor.rotate(motor1, 60, CW);//run motor1 at 60% speed in CW direction
    }


    if ( Ps3.data.button.cross ) {
      Serial.println("Pressing the cross button");
      motor.brake(1);
    }

    delay(20);

  }
}
