// Note that this header intentionally does not use include
// guards. The intended usage of this file is to define the meaning of
// the CUDA_FN macros, and then include this file, sometimes
// repeatedly within the same compilation unit.

#define STRINGIFY(name) #name

#if defined(__CUDA_API_VERSION_INTERNAL) || defined(CUDA_API_PER_THREAD_DEFAULT_STREAM)
#define __CUDA_API_PER_THREAD_DEFAULT_STREAM
#define __CUDA_API(api) STRINGIFY(api)
#define __CUDA_API_PTDS(api) STRINGIFY(api##_ptds)
#define __CUDA_API_PTSZ(api) STRINGIFY(api##_ptsz)
#else
#define __CUDA_API(api) STRINGIFY(api)
#define __CUDA_API_PTDS(api) STRINGIFY(api)
#define __CUDA_API_PTSZ(api) STRINGIFY(api)
#endif

#ifndef CUDA_FN
#define CUDA_FN(ret, fn, fn_rt, args)
#endif
#ifndef CUDA_FN_OPTIONAL
#define CUDA_FN_OPTIONAL(ret, fn, fn_rt, args)
#endif
#ifndef CUDA_FN_3020
#define CUDA_FN_3020(ret, fn, fn_3020, args) CUDA_FN(ret, fn, args)
#endif
#ifndef CUDA_FN_4000
#define CUDA_FN_4000(ret, fn, fn_4000, args) CUDA_FN(ret, fn, args)
#endif

CUDA_FN(CUresult, cuInit, __CUDA_API(cuInit), (unsigned int Flags));
CUDA_FN(CUresult, cuDeviceGetCount, __CUDA_API(cuDeviceGetCount), (int *count));
CUDA_FN(CUresult, cuDeviceGet, __CUDA_API(cuDeviceGet), (CUdevice * device, int ordinal));
CUDA_FN(CUresult, cuDeviceGetAttribute, __CUDA_API(cuDeviceGetAttribute), (int *, CUdevice_attribute attrib, CUdevice dev));
CUDA_FN(CUresult, cuDeviceGetName, __CUDA_API(cuDeviceGetName), (char *, int len, CUdevice dev));
CUDA_FN(CUresult, cuDeviceTotalMem, __CUDA_API(cuDeviceTotalMem), (size_t *, CUdevice dev));
CUDA_FN_3020(CUresult, cuCtxCreate, __CUDA_API(cuCtxCreate_v2), (CUcontext * pctx, unsigned int flags, CUdevice dev));
CUDA_FN_4000(CUresult, cuCtxDestroy, __CUDA_API(cuCtxDestroy_v2), (CUcontext pctx));
CUDA_FN(CUresult, cuProfilerStop, __CUDA_API(cuProfilerStop), ());
CUDA_FN(CUresult, cuCtxGetApiVersion, __CUDA_API(cuCtxGetApiVersion), (CUcontext ctx, unsigned int *version));
CUDA_FN(CUresult, cuCtxGetDevice, __CUDA_API(cuCtxGetDevice), (CUdevice *));
CUDA_FN(CUresult, cuModuleLoadData, __CUDA_API(cuModuleLoadData), (CUmodule * module, const void *image));
CUDA_FN(CUresult, cuModuleLoadDataEx, __CUDA_API(cuModuleLoadDataEx), (CUmodule * module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues));
CUDA_FN(CUresult, cuModuleUnload, __CUDA_API(cuModuleUnload), (CUmodule module));
CUDA_FN(CUresult, cuModuleGetFunction, __CUDA_API(cuModuleGetFunction), (CUfunction * hfunc, CUmodule hmod, const char *name));
CUDA_FN_3020(CUresult, cuMemAlloc, __CUDA_API(cuMemAlloc_v2), (CUdeviceptr * dptr, size_t bytesize));
CUDA_FN_3020(CUresult, cuMemFree, __CUDA_API(cuMemFree_v2), (CUdeviceptr dptr));
CUDA_FN_3020(CUresult, cuMemcpyHtoD, __CUDA_API_PTDS(cuMemcpyHtoD_v2), (CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount));
CUDA_FN_3020(CUresult, cuMemcpyDtoH, __CUDA_API_PTDS(cuMemcpyDtoH_v2), (void *dstHost, CUdeviceptr srcDevice, size_t ByteCount));
CUDA_FN_3020(CUresult, cuMemcpyDtoD, __CUDA_API_PTDS(cuMemcpyDtoD_v2), (CUdeviceptr dstHost, CUdeviceptr srcDevice, size_t ByteCount));
CUDA_FN_3020(CUresult, cuMemcpy3D, __CUDA_API_PTDS(cuMemcpy3D_v2), (const CUDA_MEMCPY3D *pCopy));
CUDA_FN_3020(CUresult, cuMemcpyHtoDAsync, __CUDA_API_PTSZ(cuMemcpyHtoDAsync_v2), (CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream));
CUDA_FN_3020(CUresult, cuMemcpyDtoHAsync, __CUDA_API_PTSZ(cuMemcpyDtoHAsync_v2), (void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream));
CUDA_FN_3020(CUresult, cuMemcpyDtoDAsync, __CUDA_API_PTSZ(cuMemcpyDtoDAsync_v2), (CUdeviceptr dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream));
CUDA_FN_3020(CUresult, cuMemcpy3DAsync, __CUDA_API_PTSZ(cuMemcpy3DAsync_v2), (const CUDA_MEMCPY3D *pCopy, CUstream hStream));
CUDA_FN(CUresult, cuLaunchKernel, __CUDA_API_PTSZ(cuLaunchKernel), (CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra));
CUDA_FN(CUresult, cuCtxSynchronize, __CUDA_API(cuCtxSynchronize), ());

CUDA_FN_4000(CUresult, cuCtxPushCurrent, __CUDA_API(cuCtxPushCurrent_v2), (CUcontext ctx));
CUDA_FN_4000(CUresult, cuCtxPopCurrent, __CUDA_API(cuCtxPopCurrent_v2), (CUcontext * pctx));

CUDA_FN(CUresult, cuPointerGetAttribute, __CUDA_API(cuPointerGetAttribute), (void *result, int query, CUdeviceptr ptr));

CUDA_FN_OPTIONAL(CUresult, cuStreamSynchronize, __CUDA_API_PTSZ(cuStreamSynchronize), (CUstream hStream));

#undef CUDA_FN
#undef CUDA_FN_OPTIONAL
#undef CUDA_FN_3020
#undef CUDA_FN_4000
