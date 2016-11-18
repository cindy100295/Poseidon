import de.voidplus.leapmotion.*;
import vsync.*;
import processing.serial.*;
ValueSender sender;
boolean flag;
public int index=0;
float imgPosX;
float imgPosY;
float x;
float z;
float SPEED;
float dx, dy;
int handSpeed;
float lastSPEED;
PVector v1, v2;
PVector a1, a2, a3, a4;
PVector[] a  = new PVector[4];
boolean lastFlag;
float px, py;
LeapMotion leap;
PImage img;
float easing=0.05;
int direction;
int lastDirection;

void setup() {
    index = 0;
    Serial serial = new Serial(this, "COM3", 19200);
    sender = new ValueSender(this, serial);
    sender.observe("index");

  
  size(960  , 720);
  background(255);
  frameRate(30);
  v1 = new PVector(0, 0);

  a1 = new PVector(-200, 100); 
  a2 = new PVector(200, 300); 
  a3 = new PVector(600, -100); 
  a4 = new PVector(1000, 200); 
  imageMode(CENTER);
  img = loadImage("image.png");
  leap = new LeapMotion(this);
  a[0]=a1;
  a[1]=a2;
  a[2]=a3;
  a[3]=a4;

  direction = 0;
  lastDirection = 0;
  handSpeed = 25;
}

void draw() {
  background(255);



  for (Hand hand : leap.getHands ())
  {
    x = hand.getMiddleFinger().getRawPositionOfJointMcp().x;
    z = hand.getMiddleFinger().getRawPositionOfJointMcp().z;
    imgPosX = x*15;
    imgPosY = z*15;
    ellipse(x+200, z+200, 20, 20);
    hand.draw();
  }
  if (SPEED>handSpeed&&direction==0) {
    // flag = true;
    direction = 1;
  } else if (SPEED<-handSpeed&&direction==0) {
    direction = -1;
  }
  ///---------------------------------------------------direction
  if (direction!=lastDirection && direction == 1) {
    if (index>=3) {
      index = 0;
    } else {
      index+=1;
    }
  }
    if (direction!=lastDirection && direction == -1) {
    if (index<=0) {
      index = 3;
    } else {
      index-=1;
    }
  }
  //---------------------------------------------------
  if (direction !=0 ) {
    dx = a[index].x -v1.x;
    v1.x+=dx*easing;
    dy = a[index].y -v1.y;
    v1.y+=dy*easing;
    if (abs(dx)<20&&abs(dy)<20) {
      //flag = false;
      direction = 0;
    }
  }
  image(img, v1.x, v1.y);
  SPEED = variableEllipse(x, z, px, py);
  px = x;
  py = z;
  lastSPEED = SPEED;
  lastFlag = flag;
  lastDirection = direction;
}




float variableEllipse(float x, float y, float px, float py) {
  float speed = (x-px) + (y-py);
  stroke(speed);

  ellipse(x+200, y+200, speed, speed);
  print("px:", px);
  print(" ");
  print("py:", py);
  print(" ");
  print("speed:", SPEED);
  print(" ");
  print("direction:", direction);
  print(" ");

  print("dx:", dx);
  print(" ");

  print("dy:", dy);
  print(" ");

  println("index:", index);
  return speed;
}