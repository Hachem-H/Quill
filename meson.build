project('Quill', 'cpp')

imgui = static_library('imgui',
  sources: [
    'Vendor/imgui/imgui.cpp',
    'Vendor/imgui/imgui_draw.cpp',
    'Vendor/imgui/imgui_tables.cpp',
    'Vendor/imgui/imgui_widgets.cpp',
    'Vendor/imgui/imgui_demo.cpp',
    
    'Vendor/imgui/backends/imgui_impl_opengl3.cpp',
    'Vendor/imgui/backends/imgui_impl_glfw.cpp'
  ],
  
  include_directories: include_directories('Vendor/imgui'),
)

quillSourceFiles = [
  'src/Core/Application.cc',
  'src/Core/Log.cc',

  'src/UI/PreviewPane.cc',
  'src/UI/MainView.cc',
  
  'src/main.cc',
]

quillIncludeDirectories = [
  include_directories('Vendor/imgui'),
  include_directories('Vendor/glfw/include'),

  include_directories('src'),
]

executable('quill', 
  sources: quillSourceFiles,
  include_directories: quillIncludeDirectories,

  link_with: [imgui],
  link_args: '-lglfw',

  dependencies: [ dependency('gl') ]
)
