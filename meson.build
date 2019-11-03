project('vsrawsource', 'c',
  default_options : ['buildtype=release', 'b_ndebug=if-release', 'c_std=c99'],
  meson_version : '>=0.48.0'
)

add_project_arguments('-ffast-math', language : 'c')

sources = [
  'rawsource.c'
]

vapoursynth_dep = dependency('vapoursynth').partial_dependency(compile_args : true, includes : true)

if host_machine.cpu_family().startswith('x86')
  add_project_arguments('-mfpmath=sse', '-msse2', language : 'c')
endif

shared_module('vsrawsource', sources,
  dependencies : vapoursynth_dep,
  install : true,
  install_dir : join_paths(vapoursynth_dep.get_pkgconfig_variable('libdir'), 'vapoursynth'),
  gnu_symbol_visibility : 'hidden'
)
