// -*- C++ -*-
/*!
 * @file  LEDController.cpp
 * @brief LED Controller
 * @date $Date$
 *
 * $Id$
 */

#include "LEDController.h"

// Module specification
// <rtc-template block="module_spec">
static const char* ledcontroller_spec[] =
  {
    "implementation_id", "LEDController",
    "type_name",         "LEDController",
    "description",       "LED Controller",
    "version",           "1.0.0",
    "vendor",            "yumin05cim",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
LEDController::LEDController(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_stateIn("state", m_state),
    m_led_rOut("led_r", m_led_r),
    m_led_fOut("led_f", m_led_f),
    m_led_lOut("led_l", m_led_l),
    m_led_bOut("led_b", m_led_b)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
LEDController::~LEDController()
{
}



RTC::ReturnCode_t LEDController::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("state", m_stateIn);
  
  // Set OutPort buffer
  addOutPort("led_r", m_led_rOut);
  addOutPort("led_f", m_led_fOut);
  addOutPort("led_l", m_led_lOut);
  addOutPort("led_b", m_led_bOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LEDController::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t LEDController::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LEDController::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LEDController::onExecute(RTC::UniqueId ec_id)
{
	if( m_stateIn.isNew() ){
		m_stateIn.read();

		switch (m_state.data){
		case 10:	//NO_Obs
			m_led_r.data = 0x0F0;	//G
			m_led_f.data = 0x0F0;	//G
			m_led_l.data = 0x0F0;	//G
			m_led_b.data = 0x0F0;	//G
			break;

		case 13:	//Obs_RL
			m_led_r.data = 0xF00;	//R
			m_led_f.data = 0x0F0;	//G
			m_led_l.data = 0xF00;	//R
			m_led_b.data = 0x0F0;	//G
			break;

		case 11:	//Obs_RFL
		case 16:	//Obs_F
			m_led_r.data = 0xFF0;	//Y
			m_led_f.data = 0xF00;	//R
			m_led_l.data = 0xFF0;	//Y
			m_led_b.data = 0x0F0;	//G
			break;

		case 12:	//Obs_RF
		case 15:	//Obs_R
			m_led_r.data = 0xF00;	//R
			m_led_f.data = 0xFF0;	//Y
			m_led_l.data = 0x0F0;	//G
			m_led_b.data = 0x0F0;	//G
			break;

		case 14:	//Obs_FL
		case 17:	//Obs_L
			m_led_r.data = 0x0F0;	//G
			m_led_f.data = 0xFF0;	//Y
			m_led_l.data = 0xF00;	//R
			m_led_b.data = 0x0F0;	//G
			break;

		default:
			m_led_r.data = 0x000;
			m_led_f.data = 0x000;
			m_led_l.data = 0x000;
			m_led_b.data = 0x000;
		}

		m_led_rOut.write();
		m_led_fOut.write();
		m_led_lOut.write();
		m_led_bOut.write();
	}

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LEDController::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LEDController::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void LEDControllerInit(RTC::Manager* manager)
  {
    coil::Properties profile(ledcontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<LEDController>,
                             RTC::Delete<LEDController>);
  }
  
};


