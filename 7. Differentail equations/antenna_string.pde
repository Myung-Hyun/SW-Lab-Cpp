class emWave {
  emWave() {
  
  };
  emWave(float f) {
    c=3e8;
    omega = 2*PI*f;
    k=omega/c;
    dt=1./f/30;
    dr=c/f/30;
    rlimit = dr*tpoints;
    Io=40;
    t=0;
  }

  int tpoints = 200; /* total points along string */
  float Arn[], Arnp1[], Arnm1[];   /* values at time t */
  float c, omega, k, t, r, Io;
  float dr, dt, rlimit;
  void init_line()
  {

    Arn[0]=Io*sin(omega*t);
    Arn[1]=Arn[0]+(-Io/PI)*cos(omega*t);
    // sine function
    for (r=dr;r<rlimit; r+=dr) {
      R2=R1+(r-dr/2)/(r+dr/2)*(R1-R0)-k*k*R1*r*dr*dr/(r+dr/2);     // initial condition f(x, t)
      // initial condition f(x, t-dt) = f(x, t)
    } 
    
  }

 
  void update()
  {
    /* Update points along line for this time step */
    R0=Io*sin(omega*t);
    R1=R0+(-Io/PI)*cos(omega*t);
    
    for(r=dr;r<rlimit; r+=dr){
      R2=R1+(r-dr/2)/(r+dr/2)*(R1-R0)-k*k*R1*r*dr*dr/(r+dr/2);
      R0=R1*cos(omega*t);
      R1=R2*cos(omega*t);
      newline();  
  }
  t+=dt;
}
  void newline(){
    stroke(255);
    line(0, height/2, width, height/2);
    stroke(0,0,255);
    line(r/rlimit*width, (0.5-R0/Io/3)*height, (r+dr)/rlimit*width, (0.5-R1/Io/3)*height);
    
  }
}
