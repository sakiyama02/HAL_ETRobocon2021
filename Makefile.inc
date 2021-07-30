COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += \

APPL_CXXOBJS += \
				Action.o\
				ArmAction.o\
				ArmDownAction.o\
				Curve.o\
				LineTrace.o\
				Straight.o\
				Turn.o\
				CarPosition.o\
				PidControl.o\
				TrapezoidControl.o\
				GaActionInfomation.o\
				GaCurveInfomation.o\
				GaPidInfomation.o\
				GaPositionCorrectionInfomation.o\
				frLog.o\
				PositionCorrection.o\
				Garage.o\
				ScenarioControl.o\
				SceneControl.o\
				SlalomBlacky.o\
				SlalomEebui.o\
				SlalomEifie.o\
				TimeAttack.o\
				ColorSensor.o\
				SensorManager.o\
				SonicSensor.o\
				SlBkActionInfomation.o\
				SlBkCurveInfomation.o\
				SlBkPidInfomation.o\
				SlBkPositionCorrectionInfomation.o\
				SlEbActionInfomation.o\
				SlEbCurveInfomation.o\
				SlEbPidInfomation.o\
				SlEbPositionCorrectionInfomation.o\
				SlEfActionInfomation.o\
				SlEfCurveInfomation.o\
				SlEfPidInfomation.o\
				SlEfPositionCorrectionInfomation.o\
				Motor.o\
				Steering.o\
				System.o\
				TiActionInfomation.o\
				TiCurveInfomation.o\
				TiPidInfomation.o\
				TiPositionCorrectionInfomation.o\

#
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries

include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
#include $(mkfile_path)/workspace/library/RyujiEv3/Makefile

endif 

# COPTS += -DMAKE_BT_DISABLE

APPL_DIRS +=\
	$(mkfile_path)workspace/src/Action\
	$(mkfile_path)workspace/src/CarData\
	$(mkfile_path)workspace/src/Control\
	$(mkfile_path)workspace/src/GarageInformation\
	$(mkfile_path)workspace/src/Logger\
	$(mkfile_path)workspace/src/PositionCorrection\
	$(mkfile_path)workspace/src/Scenario\
	$(mkfile_path)workspace/src/Sensor\
	$(mkfile_path)workspace/src/SlalomBlackyInfomation\
	$(mkfile_path)workspace/src/SlalomEebuiInfomation\
	$(mkfile_path)workspace/src/SlalomEifieInfomation\
	$(mkfile_path)workspace/src/Steering\
	$(mkfile_path)workspace/src/System\
	$(mkfile_path)workspace/src/TimeAttackInfomation\



INCLUDES +=\
	-I$(mkfile_path)workspace/include/Action\
	-I$(mkfile_path)workspace/include/CarData\
	-I$(mkfile_path)workspace/include/Control\
	-I$(mkfile_path)workspace/include/GarageInformation\
	-I$(mkfile_path)workspace/include/Logger\
	-I$(mkfile_path)workspace/include/PositionCorrection\
	-I$(mkfile_path)workspace/include/Scenario\
	-I$(mkfile_path)workspace/include/Sensor\
	-I$(mkfile_path)workspace/include/SlalomBlackyInfomation\
	-I$(mkfile_path)workspace/include/SlalomEebuiInfomation\
	-I$(mkfile_path)workspace/include/SlalomEifieInfomation\
	-I$(mkfile_path)workspace/include/Steering\
	-I$(mkfile_path)workspace/include/System\
	-I$(mkfile_path)workspace/include/TimeAttackInfomation\


COPTS += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common
COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
COPTS += -std=gnu++11
COPTS += -fno-threadsafe-statics
COPTS += -DMAKE_EV3
