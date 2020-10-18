emWave s;
void setup(){
  size(1000,800);
  stroke(0,0,255);
  s = new emWave(1000000); //k->freq

  //frameRate(200);
}
void draw(){  
  background(120);
  s.update();

}
