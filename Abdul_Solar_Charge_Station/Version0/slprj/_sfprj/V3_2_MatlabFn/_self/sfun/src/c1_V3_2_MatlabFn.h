#ifndef __c1_V3_2_MatlabFn_h__
#define __c1_V3_2_MatlabFn_h__

/* Type Definitions */
#ifndef typedef_SFc1_V3_2_MatlabFnInstanceStruct
#define typedef_SFc1_V3_2_MatlabFnInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_V3_2_MatlabFn;
  void *c1_fEmlrtCtx;
  real_T *c1_route_pvOrGrid2bms;
  real_T *c1_en_mppt;
  real_T *c1_en_batt_grid;
  real_T *c1_en_grid_batt;
  real_T *c1_en_bat_ev_charge;
  real_T *c1_en_batt_charg;
  real_T *c1_en_ev_charg;
  boolean_T *c1_peak_time;
  boolean_T *c1_off_peak;
  boolean_T *c1_morning;
  boolean_T *c1_evening;
  int8_T *c1_bypassTime;
  real_T *c1_bms_batt_cap;
  real_T *c1_ev_batt_cap;
  real_T *c1_ev_batt_cur;
} SFc1_V3_2_MatlabFnInstanceStruct;

#endif                                 /*typedef_SFc1_V3_2_MatlabFnInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_V3_2_MatlabFn_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_V3_2_MatlabFn_get_check_sum(mxArray *plhs[]);
extern void c1_V3_2_MatlabFn_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
