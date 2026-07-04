
#import <Foundation/Foundation.h>
#import "MobilUtils_iOS_Mic_Request_ext.h"
#include <AVFoundation/AVFoundation.h>


const int EVENT_OTHER_SOCIAL = 70;
extern "C" void dsMapClear(int _dsMap );
extern "C" int dsMapCreate();
extern "C" void dsMapAddInt(int _dsMap, char* _key, int _value);
//extern "C" void dsMapAddDouble(int _dsMap, char* _key, double _value);
//extern "C" void DsMapAddString(int _dsMap, char* _key, char* _value);

extern "C" int dsListCreate();
extern "C" void dsListAddInt(int _dsList, int _value);
extern "C" void dsListAddString(int _dsList, char* _value);
extern "C" const char* dsListGetValueString(int _dsList, int _listIdx);
extern "C" double dsListGetValueDouble(int _dsList, int _listIdx);
extern "C" int dsListGetSize(int _dsList);

extern int CreateDsMap( int _num, ... );
extern void CreateAsynEventWithDSMap(int dsmapindex, int event_index);
extern "C" void dsMapAddDouble(int _dsMap, const char* _key, double _value);
extern "C" void dsMapAddString(int _dsMap, const char* _key, const char* _value);
	
	
@implementation MobilUtils_iOS_Mic_Request_ext


-(double)MobilUtils_iOS_Mic_Check
{
	switch ([[AVAudioSession sharedInstance] recordPermission]) {
    case AVAudioSessionRecordPermissionGranted:
        return 0;
    case AVAudioSessionRecordPermissionDenied:
        return 1;
    case AVAudioSessionRecordPermissionUndetermined:
		return 2;
    default:
        return 3;
	}
}

-(double) MobilUtils_iOS_Mic_Request
{
	[[AVAudioSession sharedInstance]requestRecordPermission:^(BOOL granted) 
	{
		// Check for granted
		int _dsMap = dsMapCreate();
		dsMapAddString(_dsMap, "type", "MobilUtils_iOS_Mic_Request");
		dsMapAddInt(_dsMap, "granted", granted?1.0:0.0);
		CreateAsynEventWithDSMap(_dsMap, EVENT_OTHER_SOCIAL);
	}];	
	
	return 0;
}

@end
