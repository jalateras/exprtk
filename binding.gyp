{
  "targets": [
    {
      "target_name"  : "exprtk",
      "conditions": [
        ["OS=='mac'", {
          "xcode_settings": {
            "GCC_ENABLE_CPP_RTTI": "YES",
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
          },
        }]
      ],
      "sources": [
        "lib/exprtk.cpp"
      ],
      'cflags!': [
        '-fno-exceptions'
       ],
      'cflags_cc!': [
        '-fno-exceptions'
      ],
      "cflags": [
        '-Wall',
        '-O2',
        '-O3',
        '-std=c++1'
      ]
    }
  ]
}