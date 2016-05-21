// nightWiring

#ifdef __cplusplus
extern "C" {
#endif

extern int  softToneCreate (int pin);
extern void softToneStop   (int pin);
extern void softToneWrite  (int pin, int freq);

#ifdef __cplusplus
}
#endif
