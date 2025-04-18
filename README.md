# Shahidi.VR Native Plugin

This Android NDK / IL2CPP plugin implements native features for the Shahidi.VR XR app.

## Prerequisites
- Android NDK r26 installed and `NDK_HOME` environment variable set.
- OpenXR loader and headers (
  e.g. installed via `android sdkmanager "ndk;25.2.9519653"`
).
- Oculus Mobile SDK (v57+) unzipped; set `OVR_MOBILE_SDK` to its path.
- Unity project configured for IL2CPP ARM64.

## Build Instructions
1. Create folder `NativePlugin/android` and place `CMakeLists.txt` inside.
2. From terminal run:
   ```bash
   mkdir build && cd build
   cmake .. \
     -DANDROID_ABI=arm64-v8a \
     -DANDROID_NDK=$NDK_HOME \
     -DANDROID_PLATFORM=android-26 \
     -DCMAKE_BUILD_TYPE=Release
   cmake --build . --target NativePlugin
