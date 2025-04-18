#include <openxr/openxr.h>
#include <jni.h>
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "NativeHandTrack", __VA_ARGS__))

static PFN_xrCreateHandTrackerEXT xrCreateHandTrackerEXT = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_com_shahidi_vr_NativePlugin_initializeHandTracking(JNIEnv* env, jclass, jlong instance)
{
    XrInstance xrInstance = (XrInstance)instance;
    xrGetInstanceProcAddr(xrInstance, "xrCreateHandTrackerEXT", (PFN_xrVoidFunction*)&xrCreateHandTrackerEXT);
    LOGI("HandTracking extension loaded");
}
