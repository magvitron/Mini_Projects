/* Include files */

#include "V3_2_MatlabFn_sfun.h"
#include "c1_V3_2_MatlabFn.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "V3_2_MatlabFn_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[20] = { "from_grid", "from_solar",
  "carPresent", "nargin", "nargout", "peak_time", "off_peak", "morning",
  "evening", "bypassTime", "bms_batt_cap", "ev_batt_cap", "ev_batt_cur",
  "route_pvOrGrid2bms", "en_mppt", "en_batt_grid", "en_grid_batt",
  "en_bat_ev_charge", "en_batt_charg", "en_ev_charg" };

/* Function Declarations */
static void initialize_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void initialize_params_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct *
  chartInstance);
static void enable_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void disable_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_V3_2_MatlabFn
  (SFc1_V3_2_MatlabFnInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_V3_2_MatlabFn
  (SFc1_V3_2_MatlabFnInstanceStruct *chartInstance);
static void set_sim_state_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void sf_gateway_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void mdl_start_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void initSimStructsc1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_b_en_ev_charg, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_V3_2_MatlabFn, const char_T
  *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_V3_2_MatlabFn(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_V3_2_MatlabFn = 0U;
}

static void initialize_params_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_V3_2_MatlabFn
  (SFc1_V3_2_MatlabFnInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_V3_2_MatlabFn
  (SFc1_V3_2_MatlabFnInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  const mxArray *c1_h_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  const mxArray *c1_i_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(8, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_en_bat_ev_charge;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *chartInstance->c1_en_batt_charg;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *chartInstance->c1_en_batt_grid;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *chartInstance->c1_en_ev_charg;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *chartInstance->c1_en_grid_batt;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *chartInstance->c1_en_mppt;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *chartInstance->c1_route_pvOrGrid2bms;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_is_active_c1_V3_2_MatlabFn;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_en_bat_ev_charge = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "en_bat_ev_charge");
  *chartInstance->c1_en_batt_charg = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "en_batt_charg");
  *chartInstance->c1_en_batt_grid = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "en_batt_grid");
  *chartInstance->c1_en_ev_charg = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "en_ev_charg");
  *chartInstance->c1_en_grid_batt = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "en_grid_batt");
  *chartInstance->c1_en_mppt = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "en_mppt");
  *chartInstance->c1_route_pvOrGrid2bms = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "route_pvOrGrid2bms");
  chartInstance->c1_is_active_c1_V3_2_MatlabFn = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
     "is_active_c1_V3_2_MatlabFn");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_V3_2_MatlabFn(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_ev_batt_cur, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_ev_batt_cap, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_bms_batt_cap, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_bypassTime, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_evening, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_morning, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_off_peak, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_peak_time, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_V3_2_MatlabFn(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_V3_2_MatlabFnMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_route_pvOrGrid2bms, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_mppt, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_batt_grid, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_grid_batt, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_bat_ev_charge, 12U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_batt_charg, 13U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_en_ev_charg, 14U);
}

static void mdl_start_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c1_chartstep_c1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  boolean_T c1_b_peak_time;
  boolean_T c1_b_off_peak;
  boolean_T c1_b_morning;
  boolean_T c1_b_evening;
  int8_T c1_b_bypassTime;
  real_T c1_b_bms_batt_cap;
  real_T c1_b_ev_batt_cap;
  real_T c1_b_ev_batt_cur;
  uint32_T c1_debug_family_var_map[20];
  real_T c1_from_grid;
  real_T c1_from_solar;
  real_T c1_carPresent;
  real_T c1_nargin = 8.0;
  real_T c1_nargout = 7.0;
  real_T c1_b_route_pvOrGrid2bms;
  real_T c1_b_en_mppt;
  real_T c1_b_en_batt_grid;
  real_T c1_b_en_grid_batt;
  real_T c1_b_en_bat_ev_charge;
  real_T c1_b_en_batt_charg;
  real_T c1_b_en_ev_charg;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_b_peak_time = *chartInstance->c1_peak_time;
  c1_b_off_peak = *chartInstance->c1_off_peak;
  c1_b_morning = *chartInstance->c1_morning;
  c1_b_evening = *chartInstance->c1_evening;
  c1_b_bypassTime = *chartInstance->c1_bypassTime;
  c1_b_bms_batt_cap = *chartInstance->c1_bms_batt_cap;
  c1_b_ev_batt_cap = *chartInstance->c1_ev_batt_cap;
  c1_b_ev_batt_cur = *chartInstance->c1_ev_batt_cur;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_from_grid, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_from_solar, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_carPresent, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_peak_time, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_off_peak, 6U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_morning, 7U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_evening, 8U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_bypassTime, 9U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_bms_batt_cap, 10U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_ev_batt_cap, 11U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_ev_batt_cur, 12U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_route_pvOrGrid2bms, 13U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_mppt, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_batt_grid, 15U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_grid_batt, 16U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_bat_ev_charge, 17U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_batt_charg, 18U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_en_ev_charg, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_from_grid = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_from_solar = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c1_b_ev_batt_cur, 1.0, -1,
        2U, c1_b_ev_batt_cur < 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
    c1_carPresent = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
    c1_carPresent = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  if (CV_EML_COND(0, 1, 0, c1_b_off_peak) && CV_EML_COND(0, 1, 1,
       CV_RELATIONAL_EVAL(4U, 0U, 1, c1_carPresent, 0.0, -1, 0U, c1_carPresent ==
        0.0)) && CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2,
        c1_b_bms_batt_cap, 80.0, -1, 2U, c1_b_bms_batt_cap < 80.0)) &&
      CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c1_b_ev_batt_cap, 90.0,
        -1, 4U, c1_b_ev_batt_cap > 90.0))) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 1, true);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_b_en_batt_charg = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
    c1_b_en_mppt = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    c1_b_route_pvOrGrid2bms = c1_from_solar;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
    c1_b_en_batt_grid = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
    c1_b_en_grid_batt = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
    c1_b_en_ev_charg = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
    c1_b_en_bat_ev_charge = 0.0;
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
    if (CV_EML_COND(0, 1, 4, c1_b_off_peak) && CV_EML_COND(0, 1, 5, c1_b_morning)
        && CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 4, c1_carPresent, 1.0,
          -1, 0U, c1_carPresent == 1.0)) && CV_EML_COND(0, 1, 7,
         CV_RELATIONAL_EVAL(4U, 0U, 5, c1_b_ev_batt_cap, 90.0, -1, 2U,
                            c1_b_ev_batt_cap < 90.0))) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
      c1_b_en_batt_charg = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
      c1_b_en_mppt = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
      c1_b_route_pvOrGrid2bms = c1_from_solar;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
      c1_b_en_batt_grid = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
      c1_b_en_grid_batt = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
      c1_b_en_ev_charg = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
      c1_b_en_bat_ev_charge = 0.0;
    } else {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 2, false);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
      if (CV_EML_COND(0, 1, 8, c1_b_peak_time) && CV_EML_COND(0, 1, 9,
           c1_b_evening) && CV_EML_COND(0, 1, 10, CV_RELATIONAL_EVAL(4U, 0U, 6,
            c1_carPresent, 1.0, -1, 0U, c1_carPresent == 1.0)) && CV_EML_COND(0,
           1, 11, CV_RELATIONAL_EVAL(4U, 0U, 7, c1_b_bms_batt_cap, 30.0, -1, 4U,
            c1_b_bms_batt_cap > 30.0)) && CV_EML_COND(0, 1, 12,
           CV_RELATIONAL_EVAL(4U, 0U, 8, c1_b_ev_batt_cap, 90.0, -1, 2U,
                              c1_b_ev_batt_cap < 90.0))) {
        CV_EML_MCDC(0, 1, 2, true);
        CV_EML_IF(0, 1, 3, true);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
        c1_b_en_batt_charg = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
        c1_b_en_mppt = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
        c1_b_route_pvOrGrid2bms = c1_from_grid;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
        c1_b_en_batt_grid = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
        c1_b_en_grid_batt = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
        c1_b_en_ev_charg = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
        c1_b_en_bat_ev_charge = 1.0;
      } else {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 3, false);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 66);
        if (CV_EML_COND(0, 1, 13, c1_b_off_peak) && CV_EML_COND(0, 1, 14,
             c1_b_morning) && CV_EML_COND(0, 1, 15, CV_RELATIONAL_EVAL(4U, 0U, 9,
              c1_carPresent, 0.0, -1, 0U, c1_carPresent == 0.0)) && CV_EML_COND
            (0, 1, 16, CV_RELATIONAL_EVAL(4U, 0U, 10, c1_b_bms_batt_cap, 80.0,
              -1, 2U, c1_b_bms_batt_cap < 80.0)) && CV_EML_COND(0, 1, 17,
             CV_RELATIONAL_EVAL(4U, 0U, 11, c1_b_ev_batt_cap, 90.0, -1, 2U,
                                c1_b_ev_batt_cap < 90.0))) {
          CV_EML_MCDC(0, 1, 3, true);
          CV_EML_IF(0, 1, 4, true);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 67);
          c1_b_en_batt_charg = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
          c1_b_en_mppt = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 69);
          c1_b_route_pvOrGrid2bms = c1_from_grid;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
          c1_b_en_batt_grid = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
          c1_b_en_grid_batt = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
          c1_b_en_ev_charg = 1.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 73);
          c1_b_en_bat_ev_charge = 0.0;
        } else {
          CV_EML_MCDC(0, 1, 3, false);
          CV_EML_IF(0, 1, 4, false);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 82);
          if (CV_EML_COND(0, 1, 18, c1_b_morning) && CV_EML_COND(0, 1, 19,
               CV_RELATIONAL_EVAL(4U, 0U, 12, c1_b_bms_batt_cap, 90.0, -1, 4U,
                                  c1_b_bms_batt_cap > 90.0)) && CV_EML_COND(0, 1,
               20, CV_RELATIONAL_EVAL(4U, 0U, 13, c1_carPresent, 0.0, -1, 0U,
                c1_carPresent == 0.0)) && CV_EML_COND(0, 1, 21,
               CV_RELATIONAL_EVAL(4U, 0U, 14, c1_b_ev_batt_cap, 90.0, -1, 4U,
                                  c1_b_ev_batt_cap > 90.0))) {
            CV_EML_MCDC(0, 1, 4, true);
            CV_EML_IF(0, 1, 5, true);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 83);
            c1_b_en_batt_charg = 1.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 84);
            c1_b_en_mppt = 1.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 85);
            c1_b_route_pvOrGrid2bms = c1_from_grid;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
            c1_b_en_batt_grid = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 87);
            c1_b_en_grid_batt = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 88);
            c1_b_en_ev_charg = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 89);
            c1_b_en_bat_ev_charge = 0.0;
          } else {
            CV_EML_MCDC(0, 1, 4, false);
            CV_EML_IF(0, 1, 5, false);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 91);
            c1_b_en_batt_charg = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 92);
            c1_b_en_mppt = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 93);
            c1_b_route_pvOrGrid2bms = c1_from_grid;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 94);
            c1_b_en_batt_grid = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 95);
            c1_b_en_grid_batt = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 96);
            c1_b_en_ev_charg = 0.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 97);
            c1_b_en_bat_ev_charge = 0.0;
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -97);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c1_route_pvOrGrid2bms = c1_b_route_pvOrGrid2bms;
  *chartInstance->c1_en_mppt = c1_b_en_mppt;
  *chartInstance->c1_en_batt_grid = c1_b_en_batt_grid;
  *chartInstance->c1_en_grid_batt = c1_b_en_grid_batt;
  *chartInstance->c1_en_bat_ev_charge = c1_b_en_bat_ev_charge;
  *chartInstance->c1_en_batt_charg = c1_b_en_batt_charg;
  *chartInstance->c1_en_ev_charg = c1_b_en_ev_charg;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_V3_2_MatlabFn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_b_en_ev_charg, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_en_ev_charg),
    &c1_thisId);
  sf_mex_destroy(&c1_b_en_ev_charg);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_en_ev_charg;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_b_en_ev_charg = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_en_ev_charg),
    &c1_thisId);
  sf_mex_destroy(&c1_b_en_ev_charg);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_V3_2_MatlabFn_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_V3_2_MatlabFn, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_V3_2_MatlabFn), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_V3_2_MatlabFn);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_V3_2_MatlabFnInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_route_pvOrGrid2bms = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_en_mppt = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_en_batt_grid = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_en_grid_batt = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_en_bat_ev_charge = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_en_batt_charg = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_en_ev_charg = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c1_peak_time = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_off_peak = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_morning = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_evening = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_bypassTime = (int8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_bms_batt_cap = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_ev_batt_cap = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_ev_batt_cur = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_V3_2_MatlabFn_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1528669148U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(709618532U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(926362013U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2535328542U);
}

mxArray* sf_c1_V3_2_MatlabFn_get_post_codegen_info(void);
mxArray *sf_c1_V3_2_MatlabFn_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("euSlTfd0M8Me426BtUszdH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_V3_2_MatlabFn_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_V3_2_MatlabFn_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_V3_2_MatlabFn_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_V3_2_MatlabFn_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_V3_2_MatlabFn_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_V3_2_MatlabFn(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[26],T\"en_bat_ev_charge\",},{M[1],M[12],T\"en_batt_charg\",},{M[1],M[10],T\"en_batt_grid\",},{M[1],M[13],T\"en_ev_charg\",},{M[1],M[11],T\"en_grid_batt\",},{M[1],M[5],T\"en_mppt\",},{M[1],M[25],T\"route_pvOrGrid2bms\",},{M[8],M[0],T\"is_active_c1_V3_2_MatlabFn\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_V3_2_MatlabFn_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_V3_2_MatlabFnInstanceStruct *chartInstance =
      (SFc1_V3_2_MatlabFnInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _V3_2_MatlabFnMachineNumber_,
           1,
           1,
           1,
           0,
           15,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_V3_2_MatlabFnMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_V3_2_MatlabFnMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _V3_2_MatlabFnMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"peak_time");
          _SFD_SET_DATA_PROPS(1,1,1,0,"off_peak");
          _SFD_SET_DATA_PROPS(2,1,1,0,"morning");
          _SFD_SET_DATA_PROPS(3,1,1,0,"evening");
          _SFD_SET_DATA_PROPS(4,1,1,0,"bypassTime");
          _SFD_SET_DATA_PROPS(5,1,1,0,"bms_batt_cap");
          _SFD_SET_DATA_PROPS(6,1,1,0,"ev_batt_cap");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ev_batt_cur");
          _SFD_SET_DATA_PROPS(8,2,0,1,"route_pvOrGrid2bms");
          _SFD_SET_DATA_PROPS(9,2,0,1,"en_mppt");
          _SFD_SET_DATA_PROPS(10,2,0,1,"en_batt_grid");
          _SFD_SET_DATA_PROPS(11,2,0,1,"en_grid_batt");
          _SFD_SET_DATA_PROPS(12,2,0,1,"en_bat_ev_charge");
          _SFD_SET_DATA_PROPS(13,2,0,1,"en_batt_charg");
          _SFD_SET_DATA_PROPS(14,2,0,1,"en_ev_charg");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,6,0,0,0,0,0,22,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4314);
        _SFD_CV_INIT_EML_IF(0,1,0,235,254,275,302);
        _SFD_CV_INIT_EML_IF(0,1,1,756,830,1544,4312);
        _SFD_CV_INIT_EML_IF(0,1,2,1544,1610,2322,4312);
        _SFD_CV_INIT_EML_IF(0,1,3,2322,2409,3115,4312);
        _SFD_CV_INIT_EML_IF(0,1,4,3115,3202,3907,4312);
        _SFD_CV_INIT_EML_IF(0,1,5,3907,3982,4143,4312);

        {
          static int condStart[] = { 761, 775, 792, 813 };

          static int condEnd[] = { 769, 788, 809, 829 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,761,829,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1552, 1564, 1576, 1593 };

          static int condEnd[] = { 1560, 1571, 1589, 1609 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1552,1609,4,4,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2330, 2343, 2355, 2372, 2392 };

          static int condEnd[] = { 2339, 2350, 2368, 2388, 2408 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,2330,2408,5,8,&(condStart[0]),&(condEnd[0]),
                                9,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3123, 3135, 3148, 3165, 3185 };

          static int condEnd[] = { 3131, 3142, 3161, 3181, 3201 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,3123,3201,5,13,&(condStart[0]),&(condEnd[0]),
                                9,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3915, 3927, 3947, 3965 };

          static int condEnd[] = { 3922, 3943, 3960, 3981 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,3915,3981,4,18,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,238,253,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,775,788,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,792,809,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,813,829,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1576,1589,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,1593,1609,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,2355,2368,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,2372,2388,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,8,2392,2408,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,9,3148,3161,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,10,3165,3181,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,11,3185,3201,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,12,3927,3943,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,13,3947,3960,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,14,3965,3981,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _V3_2_MatlabFnMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_V3_2_MatlabFnInstanceStruct *chartInstance =
      (SFc1_V3_2_MatlabFnInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c1_route_pvOrGrid2bms);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c1_en_mppt);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c1_en_batt_grid);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c1_en_grid_batt);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c1_en_bat_ev_charge);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c1_en_batt_charg);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c1_en_ev_charg);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_peak_time);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_off_peak);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_morning);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_evening);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c1_bypassTime);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c1_bms_batt_cap);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c1_ev_batt_cap);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c1_ev_batt_cur);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sdOHy5bkp1l4QSHNLBHmltF";
}

static void sf_opaque_initialize_c1_V3_2_MatlabFn(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_V3_2_MatlabFnInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
    chartInstanceVar);
  initialize_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_V3_2_MatlabFn(void *chartInstanceVar)
{
  enable_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_V3_2_MatlabFn(void *chartInstanceVar)
{
  disable_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_V3_2_MatlabFn(void *chartInstanceVar)
{
  sf_gateway_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_V3_2_MatlabFn(SimStruct* S)
{
  return get_sim_state_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_V3_2_MatlabFn(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_V3_2_MatlabFn(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_V3_2_MatlabFnInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_V3_2_MatlabFn_optimization_info();
    }

    finalize_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_V3_2_MatlabFn(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_V3_2_MatlabFn((SFc1_V3_2_MatlabFnInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_V3_2_MatlabFn(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_V3_2_MatlabFn_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1921184095U));
  ssSetChecksum1(S,(320779252U));
  ssSetChecksum2(S,(2448013478U));
  ssSetChecksum3(S,(2634118335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_V3_2_MatlabFn(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_V3_2_MatlabFn(SimStruct *S)
{
  SFc1_V3_2_MatlabFnInstanceStruct *chartInstance;
  chartInstance = (SFc1_V3_2_MatlabFnInstanceStruct *)utMalloc(sizeof
    (SFc1_V3_2_MatlabFnInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_V3_2_MatlabFnInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_V3_2_MatlabFn;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_V3_2_MatlabFn(chartInstance);
}

void c1_V3_2_MatlabFn_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_V3_2_MatlabFn(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_V3_2_MatlabFn(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_V3_2_MatlabFn(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_V3_2_MatlabFn_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
