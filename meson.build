project('vsrawsource', 'c',
  default_options : ['buildtype=release', 'b_ndebug=if-release', 'c_std=gnu99'],
  meson_version: '>=0.51.0'
)

cxx = meson.get_compiler('c')

gcc_syntax = cxx.get_argument_syntax() == 'gcc'

if gcc_syntax
  add_project_arguments('-ffast-math', '-D_FILE_OFFSET_BITS=64', language : 'c')
  vapoursynth_dep = dependency('vapoursynth').partial_dependency(compile_args: true, includes: true)
  install_dir = vapoursynth_dep.get_variable(pkgconfig: 'libdir') / 'vapoursynth'
else
  vapoursynth_dep = []
  install_dir = get_option('libdir') / 'vapoursynth'
endif

sources = [
  'rawsource.c'
]

if host_machine.cpu_family().startswith('x86') and gcc_syntax
  add_project_arguments('-mfpmath=sse', '-msse2', language : 'c')
endif

shared_module('vsrawsource', sources,
  dependencies : vapoursynth_dep,
  install : true,
  install_dir : install_dir,
  gnu_symbol_visibility : 'hidden'
)
