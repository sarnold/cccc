/* static */ int yadda(STATIC* new_static, ssim_func_port_handle func_port)
{
#if !KC_USE_STATICS_VECTOR
   return X;
#else
   return Y;
#endif
}
