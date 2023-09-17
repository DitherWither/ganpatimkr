project(
    'ganpatimkr', 'cpp',
    version : '0.1',
    default_options : ['warning_level=3', 'cpp_std=c++20']
)

gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')

project_sources = []

subdir('src')

executable(
    'ganpatimkr',
    project_sources,
    dependencies: [gtkmm_dep]
)