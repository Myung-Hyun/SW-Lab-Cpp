class emWave {
  emWave() {
    k = 1.0;

    init_param();
    init_line();
  };
  emWave(float cc) {
    k = cc;        // wave coefficient
    init_param();
    init_line();
  }

  int tpoints = 1000; /* total points along string */
  float Arn[], Arnp1[], Arnm1[];   /* values at time t */
  float k, dt, dr, t;

  void init_param()
  {
    Arn    = new float[tpoints+2];
    Arnp1  = new float[tpoints+2];
    Arnm1  = new float[tpoints+2];


    dt = 5*1e-8;
    dr = 0.3; //10m dr increase means 1 pixel big, look like far away.
    t=0;
  }
  /***************************************************************************
   *     Initial condition : initial values based on sine curve
   **************************************************************************/
  void init_line()
  {

    Arn[0]=-3*sin(6.28/1000*t);
    Arn[1]=Arn[0]+(-3/PI)*cos(6.28/100*t);
    // sine function
    for (int j = 1; j <= tpoints/2; j+=1) {
      Arn[j+1] = (j*dr*dr/(dr+j) * (Arn[j]/(j*dr)+(2*Arn[j]-Arn[j-1])/(dr*dr)-k*k*Arn[j]))/1;     // initial condition f(x, t)
      // initial condition f(x, t-dt) = f(x, t)
    } 
    for (int j = tpoints/2; j <= tpoints; j+=1) {
      Arn[j+1] = (j*dr*dr/(dr+j) * (Arn[j]/(j*dr)+(2*Arn[j]-Arn[j-1])/(dr*dr)-k*k*Arn[j]))/1.01;     // initial condition f(x, t)
           // initial condition f(x, t-dt) = f(x, t)
    } 
    /* triangle
     for (int j = 1; j <= tpoints; j++) {
     if(j<tpoints/2) fxn[j] =  (float)j / tpoints*2.0;     // initial condition f(x, t)
     else fxn[j] =  (tpoints-j) / (float)tpoints*2.0;     // initial condition f(x, t)
     fxnm1[j] = fxn[j];         // initial condition f(x, t-dt) = f(x, t)
     }*/
  }
  /***************************************************************************
   *     Update all values along line a specified number of times
   *
   *     Calculate new values using wave equation
   *     d^2 f(x,t) / dt^2 = gamma (d^2 f(x,t) / dx^2 )
   **************************************************************************/
  void update()
  {
    /* Update points along line for this time step */
    t++;
    if(t>1000){t=0;}
    
    for (int j = 1; j <= tpoints; j++) {                  // location x
      init_line();
      Arnp1[j] = Arn[j]*cos(6.28/1000*t);

    
    }
   
    /* Update old values with new values */
    for (int j = 1; j <= tpoints; j++) {
      Arnm1[j] = Arn[j];  // f(x, t-dt) = f(x, t)
      Arn[j] = Arnp1[j];  // f(x, t) = f(x, t+dt)
    }
    //// draw the result
    stroke(255);
    line(0, 400, 1000, 400);
    line(500, 0, 500, 800);
    stroke(0, 0, 255);
    for (int j = 2; j <= tpoints; j++) line(j-1, 400+Arn[j-1]*20, j, 400+Arn[j]*20);
    
  }
}
