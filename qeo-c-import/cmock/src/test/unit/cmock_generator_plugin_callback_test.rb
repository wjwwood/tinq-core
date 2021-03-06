# ==========================================
#   CMock Project - Automatic Mock Generation for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ========================================== 

require File.expand_path(File.dirname(__FILE__)) + "/../test_helper"
require 'cmock_generator_plugin_callback'

class CMockGeneratorPluginCallbackTest < Test::Unit::TestCase
  def setup
    create_mocks :config, :utils
    
    @config.expect.callback_include_count.returns(true)
    @config.expect.callback_after_arg_check.returns(false)
  
    @cmock_generator_plugin_callback = CMockGeneratorPluginCallback.new(@config, @utils)
  end

  def teardown
  end
  
  should "have set up internal accessors correctly on init" do
    assert_equal(@config, @cmock_generator_plugin_callback.config)
    assert_equal(@utils,  @cmock_generator_plugin_callback.utils)
    assert_equal(6,       @cmock_generator_plugin_callback.priority)
  end
  
  should "not include any additional include files" do 
    assert(!@cmock_generator_plugin_callback.respond_to?(:include_files))
  end
  
  should "add to instance structure" do
    function = {:name => "Oak", :args => [:type => "int*", :name => "blah", :ptr? => true], :return => test_return[:int_ptr]}
    expected = "  CMOCK_Oak_CALLBACK Oak_CallbackFunctionPointer;\n" +
               "  int Oak_CallbackCalls;\n"
    returned = @cmock_generator_plugin_callback.instance_structure(function)
    assert_equal(expected, returned)
  end
  
  should "add mock function declaration for function without arguments" do
    function = {:name => "Maple", :args_string => "void", :args => [], :return => test_return[:void]}
    expected = [ "typedef void (* CMOCK_Maple_CALLBACK)(int cmock_num_calls);\n",
                 "void Maple_StubWithCallback(CMOCK_Maple_CALLBACK Callback);\n" ].join
    returned = @cmock_generator_plugin_callback.mock_function_declarations(function)
    assert_equal(expected, returned)
  end
  
  should "add mock function declaration for function without arguments when count is also turned off" do
    function = {:name => "Maple", :args_string => "void", :args => [], :return => test_return[:void]}
    expected = [ "typedef void (* CMOCK_Maple_CALLBACK)(void);\n",
                 "void Maple_StubWithCallback(CMOCK_Maple_CALLBACK Callback);\n" ].join
    @cmock_generator_plugin_callback.include_count = false
    returned = @cmock_generator_plugin_callback.mock_function_declarations(function)
    assert_equal(expected, returned)
  end
  
  should "add mock function declaration for function with arguments" do
    function = {:name => "Maple", :args_string => "int* tofu", :args => [1], :return => test_return[:void]}
    expected = [ "typedef void (* CMOCK_Maple_CALLBACK)(int* tofu, int cmock_num_calls);\n",
                 "void Maple_StubWithCallback(CMOCK_Maple_CALLBACK Callback);\n" ].join
    returned = @cmock_generator_plugin_callback.mock_function_declarations(function)
    assert_equal(expected, returned)
  end
  
  should "add mock function declaration for function with return values" do
    function = {:name => "Maple", :args_string => "int* tofu", :args => [1], :return => test_return[:string]}
    expected = [ "typedef const char* (* CMOCK_Maple_CALLBACK)(int* tofu, int cmock_num_calls);\n",
                 "void Maple_StubWithCallback(CMOCK_Maple_CALLBACK Callback);\n" ].join
    returned = @cmock_generator_plugin_callback.mock_function_declarations(function)
    assert_equal(expected, returned)
  end
  
  should "add mock function declaration for function with return values and count is turned off" do
    function = {:name => "Maple", :args_string => "int* tofu", :args => [1], :return => test_return[:string]}
    expected = [ "typedef const char* (* CMOCK_Maple_CALLBACK)(int* tofu);\n",
                 "void Maple_StubWithCallback(CMOCK_Maple_CALLBACK Callback);\n" ].join
    @cmock_generator_plugin_callback.include_count = false
    returned = @cmock_generator_plugin_callback.mock_function_declarations(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'void func(void)'" do
    function = {:name => "Apple", :args => [], :args_string => "void", :return => test_return[:void]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    Mock.Apple_CallbackFunctionPointer(Mock.Apple_CallbackCalls++);\n",
                "    return;\n",
                "  }\n"
               ].join
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'void func(void)' when count turned off" do
    function = {:name => "Apple", :args => [], :args_string => "void", :return => test_return[:void]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    Mock.Apple_CallbackFunctionPointer();\n",
                "    return;\n",
                "  }\n"
               ].join
    @cmock_generator_plugin_callback.include_count = false
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'int func(void)'" do
    function = {:name => "Apple", :args => [], :args_string => "void", :return => test_return[:int]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    return Mock.Apple_CallbackFunctionPointer(Mock.Apple_CallbackCalls++);\n",
                "  }\n"
               ].join
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'void func(int* steak, uint8_t flag)'" do
    function = {:name => "Apple", 
                :args => [ { :type => 'int*', :name => 'steak', :ptr? => true},
                  { :type => 'uint8_t', :name => 'flag', :ptr? => false} ], 
                :args_string => "int* steak, uint8_t flag",
                :return=> test_return[:void]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    Mock.Apple_CallbackFunctionPointer(steak, flag, Mock.Apple_CallbackCalls++);\n",
                "    return;\n",
                "  }\n"
               ].join
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'void func(int* steak, uint8_t flag)' when count turned off" do
    function = {:name => "Apple", 
                :args => [ { :type => 'int*', :name => 'steak', :ptr? => true},
                  { :type => 'uint8_t', :name => 'flag', :ptr? => false} ], 
                :args_string => "int* steak, uint8_t flag",
                :return=> test_return[:void]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    Mock.Apple_CallbackFunctionPointer(steak, flag);\n",
                "    return;\n",
                "  }\n"
               ].join
    @cmock_generator_plugin_callback.include_count = false
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end

  should "add mock function implementation for functions of style 'int16_t func(int* steak, uint8_t flag)'" do
    function = {:name => "Apple", 
                :args => [ { :type => 'int*', :name => 'steak', :ptr? => true},
                  { :type => 'uint8_t', :name => 'flag', :ptr? => false} ],
                :args_string => "int* steak, uint8_t flag", 
                :return => test_return[:int]}
    expected = ["  if (Mock.Apple_CallbackFunctionPointer != NULL)\n",
                "  {\n",
                "    return Mock.Apple_CallbackFunctionPointer(steak, flag, Mock.Apple_CallbackCalls++);\n",
                "  }\n"
               ].join
    returned = @cmock_generator_plugin_callback.mock_implementation_precheck(function)
    assert_equal(expected, returned)
  end
  
  should "add mock interfaces for functions " do
    function = {:name => "Lemon", 
                :args => [{ :type => "char*", :name => "pescado"}], 
                :args_string => "char* pescado",
                :return => test_return[:int]
               }
     
    expected = ["void Lemon_StubWithCallback(CMOCK_Lemon_CALLBACK Callback)\n",
                "{\n",
                "  Mock.Lemon_CallbackFunctionPointer = Callback;\n",
                "}\n\n"
               ].join
    returned = @cmock_generator_plugin_callback.mock_interfaces(function)
    assert_equal(expected, returned)
  end

  should "add mock destroy for functions" do
    function = {:name => "Peach", :args => [], :return => test_return[:void] }
    expected = "  Mock.Peach_CallbackFunctionPointer = NULL;\n" +
               "  Mock.Peach_CallbackCalls = 0;\n"
    returned = @cmock_generator_plugin_callback.mock_destroy(function)
    assert_equal(expected, returned)
  end
end
