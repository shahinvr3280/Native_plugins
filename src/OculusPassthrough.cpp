#include <openxr/openxr.h>
#include <jni.h>
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "NativePassthrough", __VA_ARGS__))

static PFN_xrCreatePassthroughFB xrCreatePassthroughFB = nullptr;
static PFN_xrPassthroughStartFB xrPassthroughStartFB = nullptr;
static PFN_xrPassthroughPauseFB xrPassthroughPauseFB = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_com_shahidi_vr_NativePlugin_initializePassthrough(JNIEnv* env, jclass, jlong instance)
{
    XrInstance xrInstance = (XrInstance)instance;
    // Load OpenXR passthrough functions
    xrGetInstanceProcAddr(xrInstance, "xrCreatePassthroughFB", (PFN_xrVoidFunction*)&xrCreatePassthroughFB);
    xrGetInstanceProcAddr(xrInstance, "xrPassthroughStartFB", (PFN_xrVoidFunction*)&xrPassthroughStartFB);
    xrGetInstanceProcAddr(xrInstance, "xrPassthroughPauseFB", (PFN_xrVoidFunction*)&xrPassthroughPauseFB);
    LOGI("Passthrough functions loaded");
}

extern "C" JNIEXPORT void JNICALL
Java_com_shahidi_vr_NativePlugin_startPassthrough(JNIEnv*, jclass)
{
    if (xrPassthroughStartFB)
        xrPassthroughStartFB( /* passthrough handle */ XR_NULL_HANDLE );
}

extern "C" JNIEXPORT void JNICALL
Java_com_shahidi_vr_NativePlugin_pausePassthrough(JNIEnv*, jclass)
{
    if (xrPassthroughPauseFB)
        xrPassthroughPauseFB( /* passthrough handle */ XR_NULL_HANDLE );
}
