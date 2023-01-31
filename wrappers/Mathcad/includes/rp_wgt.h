LRESULT rp_Wgt(
    LPCOMPLEXSCALAR     ret,
    LPCMCSTRING       fluid,
    LPCCOMPLEXSCALAR      t   )
{
    char herr[255];
    int kph = 2;       //  kph = 1 (saturated liquid conc.); kph = 2 (saturated vapor conc.)
    ierr = 0;
    double psat,tsat,rhol,rhov,xliq[20],xvap[20];
    double U, H, S, Cv, Cp, W, hjt;

    ierr = cSetup(fluid->str);
    if (ierr > 0)
        return MAKELRESULT(ierr,1);
    
    if( t->imag != 0.0 )
        return MAKELRESULT(MUST_BE_REAL,2);
    else
        tsat = t->real;

    SATTdll(&tsat, &x[0], &kph, &psat, &rhol, &rhov, &xliq[0], &xvap[0], &ierr, herr, errormessagelength);

    if (ierr > 0)
    {
        if ((ierr == 1)||(ierr == 9)||(ierr == 121)) 
            return MAKELRESULT(T_OUT_OF_RANGE,2); // Temperature too low | negative | > Tcrit
        else
            return MAKELRESULT(UNCONVERGED,2); // failed to converge
    }

    THERMdll(&tsat, &rhov, &x[0], &psat, &U, &H, &S, &Cv, &Cp, &W, &hjt);

    ret->real = W;

    return 0;               // return 0 to indicate there was no error
            
}

FUNCTIONINFO    rp_wgt = 
{ 
    (char *)("rp_wgt"),                          // Name by which mathcad will recognize the function
    (char *)("fluid,t"),                                // rp_wgt will be called as rp_wgt(fluid,t)
    (char *)("Returns the saturation vapor speed of sound [m/s] given the temperature [K]"),
                                        // description of rp_wgt(fluid,t)
    (LPCFUNCTION)rp_Wgt,               // pointer to the executable code
    COMPLEX_SCALAR,                     // the return type is a complex scalar
    2,                                  // the function takes on 1 argument
    { MC_STRING,
      COMPLEX_SCALAR }                  // argument is a complex scalar
};
