/*Using the same definition of coordinate systems as in Monochromator.comp
  Counterclockwise rotation of the coordinate system is positive. */
void dmtas_rotate(double *x,double *y,double *z,double *vx,double *vy,
  double *vz,double r, double theta, double ang)
{
 double old_x=*x,old_y=*y,old_vx=*vx,old_vy=*vy,cos_t,sin_t;
 cos_t	=	cos(theta);
 sin_t	=	sin(theta);
 *x	=	r*ang+(old_x-r*ang)*cos_t-old_y*sin_t;
 *y	=	(old_x-r*ang)*sin_t+old_y*cos_t;
 *vx	=	old_vx*cos_t-old_vy*sin_t;
 *vy	=	old_vx*sin_t+old_vy*cos_t;
 /*z and vz remain the same.*/
}


void dmtas_rotate1(double *x,double *y,double *z,double *vx,double *vy,
  double *vz,double r, double theta)
{
 double old_x=*x,old_y=*y,old_vx=*vx,old_vy=*vy,cos_t,sin_t;
 cos_t	=	cos(theta);
 sin_t	=	sin(theta);
 *x	=	r+(old_x-r)*cos_t-old_y*sin_t;
 *y	=	(old_x-r)*sin_t+old_y*cos_t;
 *vx	=	old_vx*cos_t-old_vy*sin_t;
 *vy	=	old_vx*sin_t+old_vy*cos_t;
 /*z and vz remain the same.*/
}
/*A copy of the codes from monochromator.comp*/
void dmtas_analyzerblade(double div_cutoff, double zmin,double zmax,
  double ymin, double ymax, double mosaich, double mosaicv, double r0, 
  double Q, double *x, double *y, double *z, double *vx, double *vy, 
  double *vz, double *t, double *sx, double *sy, double *sz, double *p)
{
 double dphi, tmp1,tmp2,tmp3,vratio,phi,theta0,theta,v,cs,sn;
 double old_x=*x, old_y=*y,old_z=*z,old_t=*t;
 double dt;
 dt	=-(*x)/(*vx);
 if(*vx !=0.0 && dt>=0.0)
 {
	*y+=(*vy)*dt;*z+=(*vz)*dt;*t+=dt;*x=0.0;
	if(*z>zmin && *z<zmax && *y>ymin && *y<ymax)
	{
		/*First:scattering in plane*/
		theta0	=atan2(*vx,*vz); /*neutron angle to slab */
		v	=sqrt((*vx)*(*vx)+(*vy)*(*vy)+(*vz)*(*vz));
		theta	=asin(Q2V*Q/(2.0*v));	/*Bragg's law*/
		if (theta0<0) theta=-theta;
		tmp3	=	(theta-theta0)/(MIN2RAD*mosaich);
		if(tmp3>div_cutoff)
		{
			*x=old_x;
			*y=old_y;
			*z=old_z;
			*t=old_t;
		}
		else
		{
			(*p)*=r0*exp(-tmp3*tmp3*4.*log(2)); /*Use mosaics*/
			tmp1	=2*theta;
			cs	=cos(tmp1);
			sn	=sin(tmp1);
			tmp2	=cs*(*vx)-sn*(*vz);
			*vy	=*vy;
			*vz	=cs*(*vz)+sn*(*vx);
			*vx	=tmp2;
		/*Second:scattering out of plane.
		  Approximation is that Deby-Scherrer cone is a plane*/
			phi =atan2(*vy,*vz);  /*out-of plane angle */
			dphi=(MIN2RAD*mosaicv)/(2*sqrt(2*log(2)))*randnorm();
				/*MC choice*/
		/*Vertical angle of the crystallite*/
			*vy	=(*vz)*tan(phi+2*dphi*sin(theta));
			vratio	=v/sqrt((*vx)*(*vx)+(*vy)*(*vy)+(*vz)*(*vz));
			*vz	=(*vz)*vratio;
			*vy	=(*vy)*vratio;
			*vx	=(*vx)*vratio;
		}
	}
	else
	{
		*x=old_x;
		*y=old_y;
		*z=old_z;
		*t=old_t;
	}

 }
}
/*allow random direction of analyzer blade*/
void dmtas_analyzerblade1(double div_cutoff,double zmin,double zmax,
  double ymin, double ymax, double mosaich, double mosaicv, double dirdev,
  double r0, double Q, double *x, double *y, double *z, double *vx, 
  double *vy, double *vz, double *t, double *sx, double *sy, double *sz, double *p)
{
 double dphi, tmp1,tmp2,tmp3,vratio,phi,theta0,theta,v,cs,sn;
 double old_x=*x, old_y=*y,old_z=*z,old_t=*t;
 double old_vx=*vx,old_vy=*vy,old_vz=*vz;
 double dt;
 double dirdev_1=asin(sin(MIN2RAD*dirdev)*0.707107);	/*adjust dirdev*/
 double dthz=dirdev_1/(2*sqrt(2*log(2)))*randnorm();
 double dthy=dirdev_1/(2*sqrt(2*log(2)))*randnorm();
 double cdthz=cos(dthz), sdthz=sin(dthz),cdthy=cos(dthy),sdthy=sin(dthy);
/*rotate the blade to a random direction, dthz around z, then dthy around y'*/
 *x=old_x*cdthy*cdthz+old_y*cdthy*sdthz-old_z*sdthy;
 *y=-old_x*sdthz+old_y*cdthz;
 *z=old_x*sdthy*cdthz+old_y*sdthy*sdthz+old_z*cdthy;
 *vx=old_vx*cdthy*cdthz+old_vy*cdthy*sdthz-old_vz*sdthy;
 *vy=-old_vx*sdthz+old_vy*cdthz;
 *vz=old_vx*sdthy*cdthz+old_vy*sdthy*sdthz+old_vz*cdthy;

 old_x=*x;
 old_y=*y;
 old_z=*z;
 old_t=*t;

 dt	=-(*x)/(*vx);
 if(*vx !=0.0 && dt>=0.0)
 {
	*y+=(*vy)*dt;*z+=(*vz)*dt;*t+=dt;*x=0.0;
	if(*z>zmin && *z<zmax && *y>ymin && *y<ymax)
	{  
		/*First:scattering in plane*/
		theta0	=atan2(*vx,*vz); /*neutron angle to slab */
		v	=sqrt((*vx)*(*vx)+(*vy)*(*vy)+(*vz)*(*vz));
		theta	=asin(Q2V*Q/(2.0*v));	/*Bragg's law*/
		if (theta0<0) theta=-theta;
		tmp3	=	(theta-theta0)/(MIN2RAD*mosaich);
		if(tmp3>div_cutoff)
		{
			*x=old_x;
			*y=old_y;
			*z=old_z;
			*t=old_t;
		}
		else
		{
			(*p)*=r0*exp(-tmp3*tmp3*4.*log(2)); /*Use mosaics*/
			/* the reflectivity is given in r0  JAR*/
			tmp1	=2*theta;
			cs	=cos(tmp1);
			sn	=sin(tmp1);
			tmp2	=cs*(*vx)-sn*(*vz);
			*vy	=*vy;
			*vz	=cs*(*vz)+sn*(*vx);
			*vx	=tmp2;
		/*Second:scattering out of plane.
		  Approximation is that Deby-Scherrer cone is a plane*/
			phi =atan2(*vy,*vz);  /*out-of plane angle */
			dphi=(MIN2RAD*mosaicv)/(2*sqrt(2*log(2)))*randnorm();
				/*MC choice*/
		/*Vertical angle of the crystallite*/
			*vy	=(*vz)*tan(phi+2*dphi*sin(theta));
			vratio	=v/sqrt((*vx)*(*vx)+(*vy)*(*vy)+(*vz)*(*vz));
			*vz	=(*vz)*vratio;
			*vy	=(*vy)*vratio;
			*vx	=(*vx)*vratio;
		}
	}
	else
	{
		*x=old_x;
		*y=old_y;
		*z=old_z;
		*t=old_t;
	}
 }
 old_x=*x;
 old_y=*y;
 old_z=*z;
 old_vx=*vx;
 old_vy=*vy;
 old_vz=*vz;

/*rotate the blade back to its original direction*/
 *x=old_x*cdthz*cdthy+old_z*cdthz*sdthy-old_y*sdthz;
 *y=old_x*sdthz*cdthy+old_z*sdthz*sdthy+old_y*cdthz;
 *z=-old_x*sdthy+old_z*cdthy;
 *vx=old_vx*cdthz*cdthy+old_vz*cdthz*sdthy-old_vy*sdthz;
 *vy=old_vx*sdthz*cdthy+old_vz*sdthz*sdthy+old_vy*cdthz;
 *vz=-old_vx*sdthy+old_vz*cdthy;

}


/*allow random direction of analyzer blade*/
/*converted from Mosaic_anisotropic.comp  */
/*Yiming Qiu 6/29/2001			  */
#define GAUSS(x,mean,rms) \
  (exp(-((x)-(mean))*((x)-(mean))/(2*(rms)*(rms)))/(sqrt(2*PI)*(rms)))

void macs_analyzerblade_ani(double zmin,double zmax,
  double ymin, double ymax, double mosaich, double mosaicv, double dirdev,
  double r0, double Q, double *x, double *y, double *z, double *vx, 
  double *vy, double *vz, double *t, double *sx, double *sy, double *sz, double *p)
{
 double sqrt8ln2	=	sqrt(8.*log(2));

 /* Values for Gauss quadrature. Taken from Brice Carnahan, H. A. Luther and
    James O Wilkes, "Applied numerical methods", Wiley, 1996, page 103. */
 double X[] = {-0.987992518020485, 0.937273392400706, 0.848206583410427,
                0.724417731360170, 0.570972172608539, 0.394151347077563,
                0.201194093997435, 0, 0.201194093997435,
                0.394151347077563, 0.570972172608539, 0.724417731360170,
                0.848206583410427, 0.937273392400706, 0.987992518020485};
 double W[] = { 0.030753241996117, 0.070366047488108, 0.107159220467172,
                0.139570677926154, 0.166269205816994, 0.186161000115562,
                0.198431485327111, 0.202578241925561, 0.198431485327111,
                0.186161000115562, 0.166269205816994, 0.139570677926154,
                0.107159220467172, 0.070366047488108, 0.030753241996117};
 /* root-mean-square of mosaic, in radians*/
 double mos_rms_y=MIN2RAD*mosaich/sqrt8ln2; 
 double mos_rms_z=MIN2RAD*mosaicv/sqrt8ln2;
 double mos_rms_max=mos_rms_y>mos_rms_z?mos_rms_y:mos_rms_z;

 double y1,z1,t1,dt,kix,kiy,kiz,ratio,order,q0x,k,q0,theta;
 double bx,by,bz,kux,kuy,kuz,ax,ay,az,phi;
 double cos_2theta,k_sin_2theta,cos_phi,sin_phi,kfx,kfy,kfz,q_x,q_y,q_z;
 double delta,p_reflect,total,c1x,c1y,c1z,width,ds_factor;
 int i;

/*adjust the blade according to dirdev*/ 
 double old_x=*x, old_y=*y,old_z=*z,old_t=*t;
 double old_vx=*vx,old_vy=*vy,old_vz=*vz;
 double dirdev_1=asin(sin(MIN2RAD*dirdev)*0.707107);	/*adjust dirdev*/
 double dthz=dirdev_1/sqrt8ln2*randnorm();
 double dthy=dirdev_1/sqrt8ln2*randnorm();
 double cdthz=cos(dthz), sdthz=sin(dthz),cdthy=cos(dthy),sdthy=sin(dthy);
/*rotate the blade to a random direction, dthz around z, then dthy around y'*/
 *x=old_x*cdthy*cdthz+old_y*cdthy*sdthz-old_z*sdthy;
 *y=-old_x*sdthz+old_y*cdthz;
 *z=old_x*sdthy*cdthz+old_y*sdthy*sdthz+old_z*cdthy;
 *vx=old_vx*cdthy*cdthz+old_vy*cdthy*sdthz-old_vz*sdthy;
 *vy=-old_vx*sdthz+old_vy*cdthz;
 *vz=old_vx*sdthy*cdthz+old_vy*sdthy*sdthz+old_vz*cdthy;


 if(*vx != 0.0 && (dt = -(*x)/(*vx)) >= 0.0)
 { /* Moving towards crystal? */
    y1 = *y + (*vy)*dt;            /* Propagate to crystal plane */
    z1 = *z + (*vz)*dt;
    t1 = *t + dt;
    if (z1>zmin && z1<zmax && y1>ymin && y1<ymax)
    { /* Intersect the crystal? */
      kix = V2K*(*vx);             /* Initial wave vector */
      kiy = V2K*(*vy);
      kiz = V2K*(*vz);
      /* Get reflection order and corresponding nominal scattering vector q0
         of correct length and direction. Only the order with the closest
         scattering vector is considered */
      ratio = -2*kix/Q;
      order = floor(ratio + .5);
      if(order == 0.0)
        order = ratio < 0 ? -1 : 1;
      /* Order will be negative when the neutron enters from the back, in
         which case the direction of Q0 is flipped. */
      if(order < 0)
        order = -order;
      /* Make sure the order is small enough to allow Bragg scattering at the
         given neutron wavelength */
      k = sqrt(kix*kix + kiy*kiy + kiz*kiz);
      kux = kix/k;              /* Unit vector along ki */
      kuy = kiy/k;
      kuz = kiz/k;
      if(order > 2*k/Q)
        order--;
      if(order > 0)             /* Bragg scattering possible? */
      {
        q0 = order*Q;
        q0x = ratio < 0 ? -q0 : q0;
        theta = asin(q0/(2*k)); /* Actual bragg angle */
        /* Make MC choice: reflect or transmit? */
        delta = asin(fabs(kux)) - theta;
        p_reflect = r0*exp(-kiz*kiz/(kiy*kiy + kiz*kiz)*(delta*delta)/
                           (2*mos_rms_y*mos_rms_y))*
                       exp(-kiy*kiy/(kiy*kiy + kiz*kiz)*(delta*delta)/
                           (2*mos_rms_z*mos_rms_z));
        if(rand01() < p_reflect)
        {                       /* Reflect */
          cos_2theta = cos(2*theta);
          k_sin_2theta = k*sin(2*theta);
          /* Get unit normal to plane containing ki and most probable kf */
          vec_prod(bx, by, bz, kix, kiy, kiz, q0x, 0, 0);
          NORM(bx,by,bz);
          bx *= k_sin_2theta;
          by *= k_sin_2theta;
          bz *= k_sin_2theta;
          /* Get unit vector normal to ki and b */
          vec_prod(ax, ay, az, bx, by, bz, kux, kuy, kuz);
          /* Compute the total scattering probability at this ki */
          total = 0;
          /* Choose integration limits, using Gaussian tail cut-off at 5 times
	   * sigma. The radius of the Debye-Scherrer cone is smaller by a
	   * factor 1/cos(theta) than the radius of the (partial) sphere
	   * describing the possible orientations of Q due to mosaicity, so we
	   * must use an integration width 1/cos(theta) greater than 5 times
	   * the mosaic. */
          ds_factor = 1/cos(theta);
          width = 5*mos_rms_max*ds_factor;
          c1x = kix*(cos_2theta-1);
          c1y = kiy*(cos_2theta-1);
          c1z = kiz*(cos_2theta-1);
          for(i = 0; i < (sizeof(X)/sizeof(double)); i++)
          {
            phi = width*X[i];
            cos_phi = cos(phi);
            sin_phi = sin(phi);
            q_x = c1x + cos_phi*ax + sin_phi*bx;
            q_y = c1y + cos_phi*ay + sin_phi*by;
            q_z = c1z + cos_phi*az + sin_phi*bz;
            p_reflect = GAUSS((q_z/q_x),0,mos_rms_y)*
                        GAUSS((q_y/q_x),0,mos_rms_z);
            total += W[i]*p_reflect;
          }
          total *= width;
          /* Choose point on Debye-Scherrer cone. Sample from a Gaussian of
	   * width 1/cos(theta) greater than the mosaic and correct for any
	   * error by adjusting the neutron weight later. */
          phi = ds_factor*mos_rms_max*randnorm();
          /* Compute final wave vector kf and scattering vector q = ki - kf */
          cos_phi = cos(phi);
          sin_phi = sin(phi);
          q_x = c1x + cos_phi*ax + sin_phi*bx;
          q_y = c1y + cos_phi*ay + sin_phi*by;
          q_z = c1z + cos_phi*az + sin_phi*bz;
          p_reflect = GAUSS((q_z/q_x),0,mos_rms_y)*
                      GAUSS((q_y/q_x),0,mos_rms_z);
          *x = 0;
          *y = y1;
          *z = z1;
          *t = t1;
          *vx = K2V*(kix+q_x);
          *vy = K2V*(kiy+q_y);
          *vz = K2V*(kiz+q_z);
          (*p) *= p_reflect/(total*GAUSS(phi,0,ds_factor*mos_rms_max));
        } /* End MC choice to reflect or transmit neutron */
      } /* End bragg scattering possible */
    } /* End intersect the crystal */
 } /* End neutron moving towards crystal */

 old_x=*x;
 old_y=*y;
 old_z=*z;
 old_vx=*vx;
 old_vy=*vy;
 old_vz=*vz;

/*rotate the blade back to its original direction*/
 *x=old_x*cdthz*cdthy+old_z*cdthz*sdthy-old_y*sdthz;
 *y=old_x*sdthz*cdthy+old_z*sdthz*sdthy+old_y*cdthz;
 *z=-old_x*sdthy+old_z*cdthy;
 *vx=old_vx*cdthz*cdthy+old_vz*cdthz*sdthy-old_vy*sdthz;
 *vy=old_vx*sdthz*cdthy+old_vz*sdthz*sdthy+old_vy*cdthz;
 *vz=-old_vx*sdthy+old_vz*cdthy;
}





/*allow random direction of analyzer blade*/
/*converted from monochromator_flat.comp  */
/*Jose A. Rodriguez 2/12/2007*/
#define GAUSS(x,mean,rms) \
  (exp(-((x)-(mean))*((x)-(mean))/(2*(rms)*(rms)))/(sqrt(2*PI)*(rms)))

void macs_mono_flat(double zmin,double zmax,
  double ymin, double ymax, double mosaich, double mosaicv, double dirdev,
  double r0, double Q, double *x, double *y, double *z, double *vx, 
  double *vy, double *vz, double *t, double *sx, double *sy, double *sz, double *p)
{
 double sqrt8ln2	=	sqrt(8.*log(2));

 /* Values for Gauss quadrature. Taken from Brice Carnahan, H. A. Luther and
    James O Wilkes, "Applied numerical methods", Wiley, 1996, page 103. */
 double X[] = {-0.987992518020485, 0.937273392400706, 0.848206583410427,
                0.724417731360170, 0.570972172608539, 0.394151347077563,
                0.201194093997435, 0, 0.201194093997435,
                0.394151347077563, 0.570972172608539, 0.724417731360170,
                0.848206583410427, 0.937273392400706, 0.987992518020485};
 double W[] = { 0.030753241996117, 0.070366047488108, 0.107159220467172,
                0.139570677926154, 0.166269205816994, 0.186161000115562,
                0.198431485327111, 0.202578241925561, 0.198431485327111,
                0.186161000115562, 0.166269205816994, 0.139570677926154,
                0.107159220467172, 0.070366047488108, 0.030753241996117};
 /* root-mean-square of mosaic, in radians*/
 double mos_rms_y=MIN2RAD*mosaich/sqrt8ln2; 
 double mos_rms_z=MIN2RAD*mosaicv/sqrt8ln2;

 
 
 double mos_rms_max=mos_rms_y>mos_rms_z?mos_rms_y:mos_rms_z,mos_sample;

 double y1,z1,t1,dt,kix,kiy,kiz,ratio,order,q0x,k,q0,theta;
 double bx,by,bz,kux,kuy,kuz,ax,ay,az,phi;
 double cos_2theta,k_sin_2theta,cos_phi,sin_phi,kfx,kfy,kfz,q_x,q_y,q_z;
 double delta,p_reflect,total,c1x,c1y,c1z,width,ds_factor;
 int i;

/*adjust the blade according to dirdev*/ 
 double old_x=*x, old_y=*y,old_z=*z,old_t=*t;
 double old_vx=*vx,old_vy=*vy,old_vz=*vz;
 double dirdev_1=asin(sin(MIN2RAD*dirdev)*0.707107);	/*adjust dirdev*/
 double dthz=dirdev_1/sqrt8ln2*randnorm();
 double dthy=dirdev_1/sqrt8ln2*randnorm();
 double cdthz=cos(dthz), sdthz=sin(dthz),cdthy=cos(dthy),sdthy=sin(dthy);
/*rotate the blade to a random direction, dthz around z, then dthy around y'*/
 *x=old_x*cdthy*cdthz+old_y*cdthy*sdthz-old_z*sdthy;
 *y=-old_x*sdthz+old_y*cdthz;
 *z=old_x*sdthy*cdthz+old_y*sdthy*sdthz+old_z*cdthy;
 *vx=old_vx*cdthy*cdthz+old_vy*cdthy*sdthz-old_vz*sdthy;
 *vy=-old_vx*sdthz+old_vy*cdthz;
 *vz=old_vx*sdthy*cdthz+old_vy*sdthy*sdthz+old_vz*cdthy;

 if(*vx != 0.0 && (dt = -(*x)/(*vx)) >= 0.0)
  {                             /* Moving towards crystal? */
    y1 = *y + (*vy)*dt;            /* Propagate to crystal plane */
    z1 = *z + (*vz)*dt;
    t1 = *t + dt;
    if (z1>zmin && z1<zmax && y1>ymin && y1<ymax)
    {                           /* Intersect the crystal? */
      kix = V2K*(*vx);             /* Initial wave vector */
      kiy = V2K*(*vy);
      kiz = V2K*(*vz);
      /* Get reflection order and corresponding nominal scattering vector q0
         of correct length and direction. Only the order with the closest
         scattering vector is considered */
      ratio = -2*kix/Q;
      order = floor(ratio + .5);
      if(order == 0.0)
        order = ratio < 0 ? -1 : 1;
      /* Order will be negative when the neutron enters from the back, in
         which case the direction of Q0 is flipped. */
      if(order < 0)
        order = -order;
      /* Make sure the order is small enough to allow Bragg scattering at the
         given neutron wavelength */
      k = sqrt(kix*kix + kiy*kiy + kiz*kiz);
      kux = kix/k;              /* Unit vector along ki */
      kuy = kiy/k;
      kuz = kiz/k;
      if(order > 2*k/Q)
        order--;
      if(order > 0)             /* Bragg scattering possible? */
      {
        q0 = order*Q;
        q0x = ratio < 0 ? -q0 : q0;
        theta = asin(q0/(2*k)); /* Actual bragg angle */
        /* Make MC choice: reflect or transmit? */
        delta = asin(fabs(kux)) - theta;
        p_reflect = r0*exp(-kiz*kiz/(kiy*kiy + kiz*kiz)*(delta*delta)/
                           (2*mos_rms_y*mos_rms_y))*
                       exp(-kiy*kiy/(kiy*kiy + kiz*kiz)*(delta*delta)/
                           (2*mos_rms_z*mos_rms_z));
        if(rand01() < p_reflect)
        {                       /* Reflect */
          cos_2theta = cos(2*theta);
          k_sin_2theta = k*sin(2*theta);
          /* Get unit normal to plane containing ki and most probable kf */
          vec_prod(bx, by, bz, kix, kiy, kiz, q0x, 0, 0);
          NORM(bx,by,bz);
          bx *= k_sin_2theta;
          by *= k_sin_2theta;
          bz *= k_sin_2theta;
          /* Get unit vector normal to ki and b */
          vec_prod(ax, ay, az, bx, by, bz, kux, kuy, kuz);
          /* Compute the total scattering probability at this ki */
          total = 0;
          /* Choose width of Gaussian distribution to sample the angle
           * phi on the Debye-Scherrer cone for the scattered neutron.
           * The radius of the Debye-Scherrer cone is smaller by a
           * factor 1/cos(theta) than the radius of the (partial) sphere
           * describing the possible orientations of Q due to mosaicity, so we
           * start with a width 1/cos(theta) greater than the largest of
           * the two mosaics. */
          mos_sample = mos_rms_max/cos(theta);
          c1x = kix*(cos_2theta-1);
          c1y = kiy*(cos_2theta-1);
          c1z = kiz*(cos_2theta-1);
          /* Loop, repeatedly reducing the sample width until it is small
           * enough to avoid sampling scattering directions with
           * ridiculously low scattering probability.
           * Use a cut-off at 5 times the gauss width for considering
           * scattering probability as well as for integration limits
           * when integrating the sampled distribution below. */
          for(;;) {
            width = 5*mos_sample;
            cos_phi = cos(width);
            sin_phi = sin(width);
            q_x = c1x + cos_phi*ax + sin_phi*bx;
            q_y = (c1y + cos_phi*ay + sin_phi*by)/mos_rms_z;
            q_z = (c1z + cos_phi*az + sin_phi*bz)/mos_rms_y;
            /* Stop when we get near a factor of 25=5^2. */
            if(q_z*q_z + q_y*q_y < (25/(2.0/3.0))*(q_x*q_x))
              break;
            mos_sample *= (2.0/3.0);
          }
          /* Now integrate the chosen sampling distribution, using a
           * cut-off at five times sigma. */
          for(i = 0; i < (sizeof(X)/sizeof(double)); i++)
          {
            phi = width*X[i];
            cos_phi = cos(phi);
            sin_phi = sin(phi);
            q_x = c1x + cos_phi*ax + sin_phi*bx;
            q_y = c1y + cos_phi*ay + sin_phi*by;
            q_z = c1z + cos_phi*az + sin_phi*bz;
            p_reflect = GAUSS((q_z/q_x),0,mos_rms_y)*
                        GAUSS((q_y/q_x),0,mos_rms_z);
            total += W[i]*p_reflect;
          }
          total *= width;
          /* Choose point on Debye-Scherrer cone. Sample from a Gaussian of
           * width 1/cos(theta) greater than the mosaic and correct for any
           * error by adjusting the neutron weight later. */
          phi = mos_sample*randnorm();
          /* Compute final wave vector kf and scattering vector q = ki - kf */
          cos_phi = cos(phi);
          sin_phi = sin(phi);
          q_x = c1x + cos_phi*ax + sin_phi*bx;
          q_y = c1y + cos_phi*ay + sin_phi*by;
          q_z = c1z + cos_phi*az + sin_phi*bz;
          p_reflect = GAUSS((q_z/q_x),0,mos_rms_y)*
                      GAUSS((q_y/q_x),0,mos_rms_z);
          *x = 0;
          *y = y1;
          *z = z1;
          *t = t1;
          *vx = K2V*(kix+q_x);
          *vy = K2V*(kiy+q_y);
          *vz = K2V*(kiz+q_z);
          (*p) *= p_reflect/(total*GAUSS(phi,0,mos_sample));
        } /* End MC choice to reflect or transmit neutron */
      } /* End bragg scattering possible */
    } /* End intersect the crystal */
  } /* End neutron moving towards crystal */

 old_x=*x;
 old_y=*y;
 old_z=*z;
 old_vx=*vx;
 old_vy=*vy;
 old_vz=*vz;

/*rotate the blade back to its original direction*/
 *x=old_x*cdthz*cdthy+old_z*cdthz*sdthy-old_y*sdthz;
 *y=old_x*sdthz*cdthy+old_z*sdthz*sdthy+old_y*cdthz;
 *z=-old_x*sdthy+old_z*cdthy;
 *vx=old_vx*cdthz*cdthy+old_vz*cdthz*sdthy-old_vy*sdthz;
 *vy=old_vx*sdthz*cdthy+old_vz*sdthz*sdthy+old_vy*cdthz;
 *vz=-old_vx*sdthy+old_vz*cdthy;
}
