<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
  <compound kind="file">
    <name>common_defs.h</name>
    <path>framework/</path>
    <filename>common__defs_8h.html</filename>
    <includes id="debug__defs_8h" name="debug_defs.h" local="yes" import="no" module="no" objc="no">framework/debug_defs.h</includes>
    <includes id="analog__in_8h" name="analog_in.h" local="yes" import="no" module="no" objc="no">framework/drivers/analog_in.h</includes>
    <includes id="digital__in__out_8h" name="digital_in_out.h" local="yes" import="no" module="no" objc="no">framework/drivers/digital_in_out.h</includes>
    <includes id="i2c_8h" name="i2c.h" local="yes" import="no" module="no" objc="no">framework/drivers/i2c.h</includes>
    <includes id="one__wire_8h" name="one_wire.h" local="yes" import="no" module="no" objc="no">framework/drivers/one_wire.h</includes>
    <includes id="pwm__out_8h" name="pwm_out.h" local="yes" import="no" module="no" objc="no">framework/drivers/pwm_out.h</includes>
    <includes id="async__worker_8h" name="async_worker.h" local="yes" import="no" module="no" objc="no">framework/os/async_worker.h</includes>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="struct">Result</class>
    <member kind="define">
      <type>#define</type>
      <name>OFF</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>a29e413f6725b2ba32d165ffaa35b01e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ON</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>ad76d1750a6cdeebd506bfcd6752554d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LOW</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>ab811d8c6ff3a505312d3276590444289</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>HIGH</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>a5bb885982ff66a2e0a0a45a8ee9c35e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TaskDelayMs</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>a0e2ad7e13eb6f3bd8f46a25f95fc468b</anchor>
      <arglist>(ms)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TaskDelayUs</name>
      <anchorfile>common__defs_8h.html</anchorfile>
      <anchor>ab59fea53f46b24ec6e5af3a206855b35</anchor>
      <arglist>(us)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>debug_defs.h</name>
    <path>framework/</path>
    <filename>debug__defs_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>CORE_TAG</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a81759c60077e3366782c2200c4f25188</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CORE_INFO</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>aa25bf7147ac87fcb0eeac1b34b57be74</anchor>
      <arglist>(format,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CORE_WARNING</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>abe8ca894ba14c1938abaf151c2636357</anchor>
      <arglist>(format,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CORE_ERROR</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a5ce0843fdacb485f1ef90456519f7f56</anchor>
      <arglist>(format,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ASSERT</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a0966b817b229d48e5ffc7feab19a0be6</anchor>
      <arglist>(cond)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ASSERT_FAIL</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a77b2ebb819749e79a365632a6da34fe7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ASSERT_MSG</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a0fe7531ed1a24b22be126715fa750e65</anchor>
      <arglist>(cond, msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static const char *</type>
      <name>get_current_task_name</name>
      <anchorfile>debug__defs_8h.html</anchorfile>
      <anchor>a38bd8932375f04ddf43e0886770a154f</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>analog_in.cpp</name>
    <path>framework/drivers/</path>
    <filename>analog__in_8cpp.html</filename>
    <includes id="analog__in_8h" name="analog_in.h" local="yes" import="no" module="no" objc="no">framework/drivers/analog_in.h</includes>
  </compound>
  <compound kind="file">
    <name>analog_in.h</name>
    <path>framework/drivers/</path>
    <filename>analog__in_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="class">AnalogIn</class>
  </compound>
  <compound kind="file">
    <name>digital_in_out.cpp</name>
    <path>framework/drivers/</path>
    <filename>digital__in__out_8cpp.html</filename>
    <includes id="digital__in__out_8h" name="digital_in_out.h" local="yes" import="no" module="no" objc="no">framework/drivers/digital_in_out.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
  </compound>
  <compound kind="file">
    <name>digital_in_out.h</name>
    <path>framework/drivers/</path>
    <filename>digital__in__out_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="class">DigitalInOut</class>
  </compound>
  <compound kind="file">
    <name>i2c.cpp</name>
    <path>framework/drivers/</path>
    <filename>i2c_8cpp.html</filename>
    <includes id="i2c_8h" name="i2c.h" local="yes" import="no" module="no" objc="no">framework/drivers/i2c.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
  </compound>
  <compound kind="file">
    <name>i2c.h</name>
    <path>framework/drivers/</path>
    <filename>i2c_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="class">I2C</class>
  </compound>
  <compound kind="file">
    <name>one_wire.cpp</name>
    <path>framework/drivers/</path>
    <filename>one__wire_8cpp.html</filename>
    <includes id="one__wire_8h" name="one_wire.h" local="yes" import="no" module="no" objc="no">framework/drivers/one_wire.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
  </compound>
  <compound kind="file">
    <name>one_wire.h</name>
    <path>framework/drivers/</path>
    <filename>one__wire_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="class">OneWire</class>
  </compound>
  <compound kind="file">
    <name>pwm_out.cpp</name>
    <path>framework/drivers/</path>
    <filename>pwm__out_8cpp.html</filename>
    <includes id="pwm__out_8h" name="pwm_out.h" local="yes" import="no" module="no" objc="no">framework/drivers/pwm_out.h</includes>
  </compound>
  <compound kind="file">
    <name>pwm_out.h</name>
    <path>framework/drivers/</path>
    <filename>pwm__out_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <class kind="class">PwmOut</class>
  </compound>
  <compound kind="file">
    <name>async_worker.cpp</name>
    <path>framework/os/</path>
    <filename>async__worker_8cpp.html</filename>
    <includes id="async__worker_8h" name="async_worker.h" local="yes" import="no" module="no" objc="no">framework/os/async_worker.h</includes>
  </compound>
  <compound kind="file">
    <name>async_worker.h</name>
    <path>framework/os/</path>
    <filename>async__worker_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <class kind="class">AsyncWorker</class>
  </compound>
  <compound kind="file">
    <name>pin_names.h</name>
    <path>framework/</path>
    <filename>pin__names_8h.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>PinName</name>
      <anchorfile>pin__names_8h.html</anchorfile>
      <anchor>a5ceb873075d76667eb54dc6a7d2734d1</anchor>
      <arglist></arglist>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a16a2e561c536a77cbfd10490ea398be6">P0</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a5f2b9323c39ee3c861a7b382d205c3d3">P1</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a5890595e16cbebb8866e1842e4bd6ec7">P2</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1abd11537f1bc31e334497ec5463fc575e">P3</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a905ad4f16a809a8f8408ed499e75be09">P4</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ac6b1847fa30bd92ff87464e39859e7c0">P5</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ae92c142c0618e235635c86ae0d73ab56">P12</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a1673d41557faa0d66134c9f8d4b348a5">P13</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ad7372990a82060a4d9aa0a7989ab6913">P14</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aa6d22a61c9f4540a6f6f83ef81fe1512">P15</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a26c101e385de28bb9767537780505083">P16</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a3419b9914590d5dc20d79a819339bdde">P17</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a524f4551119c446eabc4dda07b9785ff">P18</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a3296be30cfe1bde802963df32c13c116">P19</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a458c22e5c3564352ca5ad75a41539a93">P21</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a4920289cc0534ad0681881b635a768ce">P22</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a0c1314a13459c5f0d22489179c119f9d">P23</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1acea622d16b041c7022024470412e7543">P25</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a398372fbee48c8ecac8ab97473676348">P26</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a3f9dda335c1787b002710ca3e82f71cb">P27</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a8748950e96291086098cf2bc1a3689d7">P32</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aa22bdd3a3ae7e3284555e6b29a9830b8">P33</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a84eba633275f316a0548b934d385ba76">P34</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aad96950a5a41a5db4d5ca717c88188c7">P35</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ae091d7a8236801976e5000f4df026bbb">P36</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ae1a204283bfe594106332a0fc2bf53e3">P39</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ad88c146dfafdea37a837778a92415bc2">A0</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a6593d7b12fd418cdb35bbf438de72f66">A3</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a0c2f3adf2a48bab3adb470f4da57f3d0">A4</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ac6f2f93133905f75da4b02ccc19ab66a">A5</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a0b3d5609ee81e50809b7351e848e4698">A6</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1abe523bdcc111d8113eb54f747d89d4d7">A7</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a4657042965f502f52dcf78fdcc952651">A10</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1af4ebc728df05346e7d2f785b1ff8fc5b">A11</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a0b92b8b2602c011d1831c6c27ef74b76">A12</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1af35b705e8c57ae59e369ebc9145a9dbc">A13</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a43ba9900ff2fc7d9d32072540b2cab12">A14</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1acaba1ed05c859e5b5bf535f8514b30d7">A15</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ae801be5386e7ba61e9b6fe0035685a7c">A16</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a10c1cc2879c975b571bbcd134ea20409">A17</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1abed96dd949cb4396935419c015179413">A18</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a032aabba74fdeba97ac9fa6cf5cda257">A19</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a04f10211c9292dda8f2420c31610a8fd">DAC1</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a815519e6de32e11b7c7ab08bd6816081">DAC2</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aa48788bd63a0384007cd7d089af6c610">T0</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1ace499dea30cfce118f4fe85da0227e83">T1</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a71d2c46af01feeea54a0f541243e297b">T2</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a54b02ae91c8c6b0aac069c84b9f78178">T3</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1af47fb721aa553aad2d0f389c93c2d533">T4</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a00a36d1346d0dc796850b0b1d919dbb6">T5</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a7137cd43a7a6b0dd927243aaf6d6cb10">T6</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1af44f8f3058a58f0b67af7248b72bb833">T7</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a001cf4576062cc35bbdae2b0f81d1dce">T8</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a2f0355649dad31dc33ebe251d9f72755">T9</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a047b37855364f25ce01708c60aeabe37">SDA</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a2b8544857feae7f156fd66499634c309">SCL</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a3fe7c3be61855d309ff779c829f753f4">SCK</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aaf0bb8ed1bca594a13e0ef70dbd1cf18">MISO</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1abeb9464c1bfe56dee08d2416d52158b0">MOSI</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a8d7e99c73cd5a10adaaf4c9f9a520368">CS</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a894bf7498c07eb86feb51f6a22714fcc">TX0</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aaf3beababea43eac8cf3de397ef524c6">RX0</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a823ab66b9b4444165ed0c78444022b0b">TX2</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1a6c241d1c5bedd939e74af049a4da2b67">RX2</enumvalue>
      <enumvalue file="pin__names_8h.html" anchor="a5ceb873075d76667eb54dc6a7d2734d1aaa85f1840e282d8a8304dbc2c0d7c9b2">EN</enumvalue>
    </member>
  </compound>
  <compound kind="file">
    <name>delay.cpp</name>
    <path>framework/util/</path>
    <filename>delay_8cpp.html</filename>
    <includes id="delay_8h" name="delay.h" local="yes" import="no" module="no" objc="no">framework/util/delay.h</includes>
  </compound>
  <compound kind="file">
    <name>delay.h</name>
    <path>framework/util/</path>
    <filename>delay_8h.html</filename>
    <class kind="class">Delay</class>
  </compound>
  <compound kind="file">
    <name>config.h</name>
    <path>include/</path>
    <filename>config_8h.html</filename>
    <includes id="pin__names_8h" name="pin_names.h" local="yes" import="no" module="no" objc="no">framework/pin_names.h</includes>
    <namespace>Config</namespace>
    <member kind="variable" static="yes">
      <type>static constexpr int</type>
      <name>INVALID</name>
      <anchorfile>config_8h.html</anchorfile>
      <anchor>a28106f1b9a1cd108037a5a08e6f89d83</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ap_portal.cpp</name>
    <path>src/connectivity/</path>
    <filename>ap__portal_8cpp.html</filename>
    <includes id="ap__portal_8h" name="ap_portal.h" local="yes" import="no" module="no" objc="no">connectivity/ap_portal.h</includes>
    <includes id="ap__portal__html_8h" name="ap_portal_html.h" local="yes" import="no" module="no" objc="no">connectivity/ap_portal_html.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>ap_portal.h</name>
    <path>src/connectivity/</path>
    <filename>ap__portal_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <class kind="class">Connectivity::APPortal</class>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>ap_portal_html.h</name>
    <path>src/connectivity/</path>
    <filename>ap__portal__html_8h.html</filename>
    <member kind="variable" static="yes">
      <type>static const char *</type>
      <name>HTML_PORTAL</name>
      <anchorfile>ap__portal__html_8h.html</anchorfile>
      <anchor>a9dd983e697e2a6fa1bab4cac8c3a1897</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mqtt_client.cpp</name>
    <path>src/connectivity/</path>
    <filename>mqtt__client_8cpp.html</filename>
    <includes id="mqtt__client_8h" name="mqtt_client.h" local="yes" import="no" module="no" objc="no">connectivity/mqtt_client.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>mqtt_client.h</name>
    <path>src/connectivity/</path>
    <filename>mqtt__client_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <includes id="mqtt__client_8h" name="mqtt_client.h" local="no" import="no" module="no" objc="no">mqtt_client.h</includes>
    <class kind="class">Connectivity::MqttClient</class>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>wifi_com.cpp</name>
    <path>src/connectivity/</path>
    <filename>wifi__com_8cpp.html</filename>
    <includes id="wifi__com_8h" name="wifi_com.h" local="yes" import="no" module="no" objc="no">connectivity/wifi_com.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>wifi_com.h</name>
    <path>src/connectivity/</path>
    <filename>wifi__com_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <class kind="class">Connectivity::WiFiCom</class>
    <namespace>Connectivity</namespace>
  </compound>
  <compound kind="file">
    <name>driver.h</name>
    <path>src/core/base/</path>
    <filename>driver_8h.html</filename>
    <includes id="module_8h" name="module.h" local="yes" import="no" module="no" objc="no">src/core/base/module.h</includes>
    <class kind="class">Base::Driver</class>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>manager.cpp</name>
    <path>src/core/base/</path>
    <filename>manager_8cpp.html</filename>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <includes id="power__controller_8h" name="power_controller.h" local="yes" import="no" module="no" objc="no">src/services/power_controller.h</includes>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>manager.h</name>
    <path>src/core/base/</path>
    <filename>manager_8h.html</filename>
    <includes id="module_8h" name="module.h" local="yes" import="no" module="no" objc="no">src/core/base/module.h</includes>
    <class kind="class">Base::Manager</class>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>module.h</name>
    <path>src/core/base/</path>
    <filename>module_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="singleton_8h" name="singleton.h" local="yes" import="no" module="no" objc="no">src/core/base/singleton.h</includes>
    <class kind="class">Base::Module</class>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>service.h</name>
    <path>src/core/base/</path>
    <filename>service_8h.html</filename>
    <includes id="module_8h" name="module.h" local="yes" import="no" module="no" objc="no">src/core/base/module.h</includes>
    <class kind="class">Base::Service</class>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>singleton.h</name>
    <path>src/core/base/</path>
    <filename>singleton_8h.html</filename>
    <class kind="class">Base::Singleton</class>
    <namespace>Base</namespace>
  </compound>
  <compound kind="file">
    <name>guardian_proxy.cpp</name>
    <path>src/core/</path>
    <filename>guardian__proxy_8cpp.html</filename>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="food__feeder_8h" name="food_feeder.h" local="yes" import="no" module="no" objc="no">src/managers/food_feeder.h</includes>
    <includes id="network__controller_8h" name="network_controller.h" local="yes" import="no" module="no" objc="no">src/managers/network_controller.h</includes>
    <includes id="user__interface_8h" name="user_interface.h" local="yes" import="no" module="no" objc="no">src/managers/user_interface.h</includes>
    <includes id="water__monitor_8h" name="water_monitor.h" local="yes" import="no" module="no" objc="no">src/managers/water_monitor.h</includes>
    <includes id="real__time__clock_8h" name="real_time_clock.h" local="yes" import="no" module="no" objc="no">src/services/real_time_clock.h</includes>
    <includes id="storage__service_8h" name="storage_service.h" local="yes" import="no" module="no" objc="no">src/services/storage_service.h</includes>
    <namespace>Core</namespace>
  </compound>
  <compound kind="file">
    <name>guardian_proxy.h</name>
    <path>src/core/</path>
    <filename>guardian__proxy_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="guardian__public__interfaces_8h" name="guardian_public_interfaces.h" local="yes" import="no" module="no" objc="no">src/core/guardian_public_interfaces.h</includes>
    <includes id="module_8h" name="module.h" local="yes" import="no" module="no" objc="no">src/core/base/module.h</includes>
    <class kind="class">Core::GuardianProxy</class>
    <namespace>Core</namespace>
  </compound>
  <compound kind="file">
    <name>guardian_public_interfaces.h</name>
    <path>src/core/</path>
    <filename>guardian__public__interfaces_8h.html</filename>
    <includes id="food__feeder_8h" name="food_feeder.h" local="yes" import="no" module="no" objc="no">src/managers/food_feeder.h</includes>
    <includes id="power__controller_8h" name="power_controller.h" local="yes" import="no" module="no" objc="no">src/services/power_controller.h</includes>
    <includes id="storage__service_8h" name="storage_service.h" local="yes" import="no" module="no" objc="no">src/services/storage_service.h</includes>
    <includes id="date__time_8h" name="date_time.h" local="yes" import="no" module="no" objc="no">src/utils/date_time.h</includes>
    <class kind="class">Core::IFoodFeeder</class>
    <class kind="class">Core::INetworkController</class>
    <class kind="class">Core::IPowerController</class>
    <class kind="class">Core::IRealTimeClock</class>
    <class kind="class">Core::IStorageService</class>
    <class kind="class">Core::IUserInterface</class>
    <class kind="class">Core::IWaterMonitor</class>
    <namespace>Core</namespace>
  </compound>
  <compound kind="file">
    <name>smart_aquarium_guardian.cpp</name>
    <path>src/core/</path>
    <filename>smart__aquarium__guardian_8cpp.html</filename>
    <includes id="smart__aquarium__guardian_8h" name="smart_aquarium_guardian.h" local="yes" import="no" module="no" objc="no">src/core/smart_aquarium_guardian.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="food__feeder_8h" name="food_feeder.h" local="yes" import="no" module="no" objc="no">src/managers/food_feeder.h</includes>
    <includes id="network__controller_8h" name="network_controller.h" local="yes" import="no" module="no" objc="no">src/managers/network_controller.h</includes>
    <includes id="user__interface_8h" name="user_interface.h" local="yes" import="no" module="no" objc="no">src/managers/user_interface.h</includes>
    <includes id="water__monitor_8h" name="water_monitor.h" local="yes" import="no" module="no" objc="no">src/managers/water_monitor.h</includes>
    <includes id="power__controller_8h" name="power_controller.h" local="yes" import="no" module="no" objc="no">src/services/power_controller.h</includes>
    <includes id="real__time__clock_8h" name="real_time_clock.h" local="yes" import="no" module="no" objc="no">src/services/real_time_clock.h</includes>
    <includes id="storage__service_8h" name="storage_service.h" local="yes" import="no" module="no" objc="no">src/services/storage_service.h</includes>
  </compound>
  <compound kind="file">
    <name>smart_aquarium_guardian.h</name>
    <path>src/core/</path>
    <filename>smart__aquarium__guardian_8h.html</filename>
    <includes id="delay_8h" name="delay.h" local="yes" import="no" module="no" objc="no">framework/util/delay.h</includes>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <class kind="class">SmartAquariumGuardian</class>
  </compound>
  <compound kind="file">
    <name>graphic_display.cpp</name>
    <path>src/drivers/</path>
    <filename>graphic__display_8cpp.html</filename>
    <includes id="graphic__display_8h" name="graphic_display.h" local="yes" import="no" module="no" objc="no">src/drivers/graphic_display.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>graphic_display.h</name>
    <path>src/drivers/</path>
    <filename>graphic__display_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="pwm__out_8h" name="pwm_out.h" local="yes" import="no" module="no" objc="no">framework/drivers/pwm_out.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <class kind="class">Drivers::GraphicDisplay</class>
    <class kind="class">Drivers::GraphicDisplay::UIElement</class>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>servo.cpp</name>
    <path>src/drivers/</path>
    <filename>servo_8cpp.html</filename>
    <includes id="servo_8h" name="servo.h" local="yes" import="no" module="no" objc="no">src/drivers/servo.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>servo.h</name>
    <path>src/drivers/</path>
    <filename>servo_8h.html</filename>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <class kind="class">Drivers::Servo</class>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>tds_sensor.cpp</name>
    <path>src/drivers/</path>
    <filename>tds__sensor_8cpp.html</filename>
    <includes id="tds__sensor_8h" name="tds_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/tds_sensor.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>tds_sensor.h</name>
    <path>src/drivers/</path>
    <filename>tds__sensor_8h.html</filename>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <class kind="class">Drivers::TdsSensor</class>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>temperature_sensor.cpp</name>
    <path>src/drivers/</path>
    <filename>temperature__sensor_8cpp.html</filename>
    <includes id="temperature__sensor_8h" name="temperature_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/temperature_sensor.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>temperature_sensor.h</name>
    <path>src/drivers/</path>
    <filename>temperature__sensor_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <class kind="class">Drivers::TemperatureSensor</class>
    <namespace>Drivers</namespace>
  </compound>
  <compound kind="file">
    <name>main.cpp</name>
    <path>src/</path>
    <filename>main_8cpp.html</filename>
    <includes id="smart__aquarium__guardian_8h" name="smart_aquarium_guardian.h" local="yes" import="no" module="no" objc="no">src/core/smart_aquarium_guardian.h</includes>
    <member kind="function">
      <type>void</type>
      <name>app_main</name>
      <anchorfile>main_8cpp.html</anchorfile>
      <anchor>a630544a7f0a2cc40d8a7fefab7e2fe70</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>cloud_payloads.h</name>
    <path>src/managers/comms/</path>
    <filename>cloud__payloads_8h.html</filename>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="network__config_8h" name="network_config.h" local="yes" import="no" module="no" objc="no">src/managers/comms/network_config.h</includes>
    <includes id="memory__config__data_8h" name="memory_config_data.h" local="yes" import="no" module="no" objc="no">src/services/memory/memory_config_data.h</includes>
    <includes id="date__time_8h" name="date_time.h" local="yes" import="no" module="no" objc="no">src/utils/date_time.h</includes>
    <class kind="class">Comms::TelemetryPayload</class>
    <class kind="class">Comms::ClientAttributesPayload</class>
    <namespace>Comms</namespace>
  </compound>
  <compound kind="file">
    <name>json_parser.h</name>
    <path>src/managers/comms/</path>
    <filename>json__parser_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <class kind="class">Utils::JsonPayloadParser</class>
    <namespace>Utils</namespace>
  </compound>
  <compound kind="file">
    <name>network_config.h</name>
    <path>src/managers/comms/</path>
    <filename>network__config_8h.html</filename>
    <namespace>NetworkConfig</namespace>
    <namespace>NetworkConfig::Key</namespace>
    <namespace>NetworkConfig::Value</namespace>
    <namespace>NetworkConfig::TelemetryKeys</namespace>
    <namespace>NetworkConfig::ClientAttributes</namespace>
  </compound>
  <compound kind="file">
    <name>rpc_handler.h</name>
    <path>src/managers/comms/</path>
    <filename>rpc__handler_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="network__config_8h" name="network_config.h" local="yes" import="no" module="no" objc="no">src/managers/comms/network_config.h</includes>
    <includes id="json__parser_8h" name="json_parser.h" local="yes" import="no" module="no" objc="no">src/managers/comms/json_parser.h</includes>
    <class kind="class">Handlers::IRpcHandler</class>
    <class kind="class">Handlers::SetTempLimitsHandler</class>
    <class kind="class">Handlers::SetTdsLimitsHandler</class>
    <class kind="class">Handlers::AddFeedingScheduleHandler</class>
    <class kind="class">Handlers::DeleteFeedingScheduleHandler</class>
    <class kind="class">Handlers::FeedNowHandler</class>
    <class kind="class">Handlers::SetTimezoneHandler</class>
    <class kind="class">Handlers::FactoryResetHandler</class>
    <class kind="class">Handlers::SyncDeviceHandler</class>
    <namespace>Handlers</namespace>
  </compound>
  <compound kind="file">
    <name>food_feeder.cpp</name>
    <path>src/managers/</path>
    <filename>food__feeder_8cpp.html</filename>
    <includes id="food__feeder_8h" name="food_feeder.h" local="yes" import="no" module="no" objc="no">src/managers/food_feeder.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <includes id="servo_8h" name="servo.h" local="yes" import="no" module="no" objc="no">src/drivers/servo.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>food_feeder.h</name>
    <path>src/managers/</path>
    <filename>food__feeder_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="async__worker_8h" name="async_worker.h" local="yes" import="no" module="no" objc="no">framework/os/async_worker.h</includes>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <includes id="servo_8h" name="servo.h" local="yes" import="no" module="no" objc="no">src/drivers/servo.h</includes>
    <includes id="date__time_8h" name="date_time.h" local="yes" import="no" module="no" objc="no">src/utils/date_time.h</includes>
    <class kind="class">Managers::FoodFeeder</class>
    <class kind="struct">Managers::FoodFeeder::FeederStatus</class>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>network_controller.cpp</name>
    <path>src/managers/</path>
    <filename>network__controller_8cpp.html</filename>
    <includes id="network__controller_8h" name="network_controller.h" local="yes" import="no" module="no" objc="no">src/managers/network_controller.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <includes id="ap__portal_8h" name="ap_portal.h" local="yes" import="no" module="no" objc="no">src/connectivity/ap_portal.h</includes>
    <includes id="mqtt__client_8h" name="mqtt_client.h" local="yes" import="no" module="no" objc="no">src/connectivity/mqtt_client.h</includes>
    <includes id="wifi__com_8h" name="wifi_com.h" local="yes" import="no" module="no" objc="no">src/connectivity/wifi_com.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="guardian__public__interfaces_8h" name="guardian_public_interfaces.h" local="yes" import="no" module="no" objc="no">src/core/guardian_public_interfaces.h</includes>
    <includes id="cloud__payloads_8h" name="cloud_payloads.h" local="yes" import="no" module="no" objc="no">src/managers/comms/cloud_payloads.h</includes>
    <includes id="json__parser_8h" name="json_parser.h" local="yes" import="no" module="no" objc="no">src/managers/comms/json_parser.h</includes>
    <includes id="network__config_8h" name="network_config.h" local="yes" import="no" module="no" objc="no">src/managers/comms/network_config.h</includes>
    <includes id="storage__service_8h" name="storage_service.h" local="yes" import="no" module="no" objc="no">src/services/storage_service.h</includes>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>network_controller.h</name>
    <path>src/managers/</path>
    <filename>network__controller_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="delay_8h" name="delay.h" local="yes" import="no" module="no" objc="no">framework/util/delay.h</includes>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <includes id="rpc__handler_8h" name="rpc_handler.h" local="yes" import="no" module="no" objc="no">src/managers/comms/rpc_handler.h</includes>
    <class kind="class">Managers::NetworkController</class>
    <namespace>Connectivity</namespace>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>user_interface.cpp</name>
    <path>src/managers/</path>
    <filename>user__interface_8cpp.html</filename>
    <includes id="user__interface_8h" name="user_interface.h" local="yes" import="no" module="no" objc="no">src/managers/user_interface.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="graphic__display_8h" name="graphic_display.h" local="yes" import="no" module="no" objc="no">src/drivers/graphic_display.h</includes>
    <includes id="real__time__clock_8h" name="real_time_clock.h" local="yes" import="no" module="no" objc="no">src/services/real_time_clock.h</includes>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>user_interface.h</name>
    <path>src/managers/</path>
    <filename>user__interface_8h.html</filename>
    <includes id="delay_8h" name="delay.h" local="yes" import="no" module="no" objc="no">framework/util/delay.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <includes id="graphic__display_8h" name="graphic_display.h" local="yes" import="no" module="no" objc="no">src/drivers/graphic_display.h</includes>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <class kind="class">Managers::UserInterface</class>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>water_monitor.cpp</name>
    <path>src/managers/</path>
    <filename>water__monitor_8cpp.html</filename>
    <includes id="water__monitor_8h" name="water_monitor.h" local="yes" import="no" module="no" objc="no">src/managers/water_monitor.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <includes id="tds__sensor_8h" name="tds_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/tds_sensor.h</includes>
    <includes id="temperature__sensor_8h" name="temperature_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/temperature_sensor.h</includes>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>water_monitor.h</name>
    <path>src/managers/</path>
    <filename>water__monitor_8h.html</filename>
    <includes id="manager_8h" name="manager.h" local="yes" import="no" module="no" objc="no">src/core/base/manager.h</includes>
    <includes id="tds__sensor_8h" name="tds_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/tds_sensor.h</includes>
    <includes id="temperature__sensor_8h" name="temperature_sensor.h" local="yes" import="no" module="no" objc="no">src/drivers/temperature_sensor.h</includes>
    <class kind="class">Managers::WaterMonitor</class>
    <namespace>Managers</namespace>
  </compound>
  <compound kind="file">
    <name>eeprom_memory.cpp</name>
    <path>src/services/memory/</path>
    <filename>eeprom__memory_8cpp.html</filename>
    <includes id="eeprom__memory_8h" name="eeprom_memory.h" local="yes" import="no" module="no" objc="no">src/services/memory/eeprom_memory.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>eeprom_memory.h</name>
    <path>src/services/memory/</path>
    <filename>eeprom__memory_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="driver_8h" name="driver.h" local="yes" import="no" module="no" objc="no">src/core/base/driver.h</includes>
    <class kind="class">Services::EepromMemory</class>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>memory_config_data.h</name>
    <path>src/services/memory/</path>
    <filename>memory__config__data_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <class kind="struct">Services::FeedingScheduleEntry</class>
    <class kind="struct">Services::MemoryConfigData</class>
    <namespace>Services</namespace>
    <member kind="define">
      <type>#define</type>
      <name>CONFIG_FIELDS</name>
      <anchorfile>memory__config__data_8h.html</anchorfile>
      <anchor>ab3de00e1df9619cf7b3d90f15ab75c18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>memory__config__data_8h.html</anchorfile>
      <anchor>a8c3aef71f16cbfc1c5e22b0f6c1b141b</anchor>
      <arglist>(type, id, name, key, def)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>memory__config__data_8h.html</anchorfile>
      <anchor>a4a2a1b0fd38ad1870381d7e6b197187e</anchor>
      <arglist>(type, id, name, key, def)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>memory__config__data_8h.html</anchorfile>
      <anchor>a660aecf330297659c4605559d6c047d1</anchor>
      <arglist>(type, id, name, key, def)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>memory__config__data_8h.html</anchorfile>
      <anchor>ae0a85b739eaeb7e810b14ee5f6355a4a</anchor>
      <arglist>(T, id, name, key, def)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>power_controller.cpp</name>
    <path>src/services/</path>
    <filename>power__controller_8cpp.html</filename>
    <includes id="power__controller_8h" name="power_controller.h" local="yes" import="no" module="no" objc="no">src/services/power_controller.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>power_controller.h</name>
    <path>src/services/</path>
    <filename>power__controller_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="service_8h" name="service.h" local="yes" import="no" module="no" objc="no">src/core/base/service.h</includes>
    <class kind="class">Services::PowerController</class>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>real_time_clock.cpp</name>
    <path>src/services/</path>
    <filename>real__time__clock_8cpp.html</filename>
    <includes id="real__time__clock_8h" name="real_time_clock.h" local="yes" import="no" module="no" objc="no">src/services/real_time_clock.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="config_8h" name="config.h" local="yes" import="no" module="no" objc="no">include/config.h</includes>
    <includes id="guardian__proxy_8h" name="guardian_proxy.h" local="yes" import="no" module="no" objc="no">src/core/guardian_proxy.h</includes>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>real_time_clock.h</name>
    <path>src/services/</path>
    <filename>real__time__clock_8h.html</filename>
    <includes id="i2c_8h" name="i2c.h" local="yes" import="no" module="no" objc="no">framework/drivers/i2c.h</includes>
    <includes id="service_8h" name="service.h" local="yes" import="no" module="no" objc="no">src/core/base/service.h</includes>
    <includes id="date__time_8h" name="date_time.h" local="yes" import="no" module="no" objc="no">src/utils/date_time.h</includes>
    <class kind="class">Services::RealTimeClock</class>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>storage_service.cpp</name>
    <path>src/services/</path>
    <filename>storage__service_8cpp.html</filename>
    <includes id="storage__service_8h" name="storage_service.h" local="yes" import="no" module="no" objc="no">src/services/storage_service.h</includes>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <namespace>Services</namespace>
  </compound>
  <compound kind="file">
    <name>storage_service.h</name>
    <path>src/services/</path>
    <filename>storage__service_8h.html</filename>
    <includes id="common__defs_8h" name="common_defs.h" local="yes" import="no" module="no" objc="no">framework/common_defs.h</includes>
    <includes id="service_8h" name="service.h" local="yes" import="no" module="no" objc="no">src/core/base/service.h</includes>
    <includes id="eeprom__memory_8h" name="eeprom_memory.h" local="yes" import="no" module="no" objc="no">src/services/memory/eeprom_memory.h</includes>
    <includes id="memory__config__data_8h" name="memory_config_data.h" local="yes" import="no" module="no" objc="no">src/services/memory/memory_config_data.h</includes>
    <class kind="class">Services::StorageService</class>
    <namespace>Services</namespace>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>storage__service_8h.html</anchorfile>
      <anchor>a8c3aef71f16cbfc1c5e22b0f6c1b141b</anchor>
      <arglist>(type, id, name, key, def)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>storage__service_8h.html</anchorfile>
      <anchor>a4a2a1b0fd38ad1870381d7e6b197187e</anchor>
      <arglist>(type, id, name, key, def)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>date_time.cpp</name>
    <path>src/utils/</path>
    <filename>date__time_8cpp.html</filename>
    <includes id="date__time_8h" name="date_time.h" local="yes" import="no" module="no" objc="no">src/utils/date_time.h</includes>
    <namespace>Utils</namespace>
  </compound>
  <compound kind="file">
    <name>date_time.h</name>
    <path>src/utils/</path>
    <filename>date__time_8h.html</filename>
    <class kind="class">Utils::DateTime</class>
    <namespace>Utils</namespace>
  </compound>
  <compound kind="class">
    <name>Handlers::AddFeedingScheduleHandler</name>
    <filename>class_handlers_1_1_add_feeding_schedule_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_add_feeding_schedule_handler.html</anchorfile>
      <anchor>ab5b3c33507dc9cd9e038cb3bbf7a17e7</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_add_feeding_schedule_handler.html</anchorfile>
      <anchor>a1ac5453fe79f3e3761fefba99706cf47</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AnalogIn</name>
    <filename>class_analog_in.html</filename>
    <member kind="function">
      <type></type>
      <name>AnalogIn</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a6f872cff3f3aa4ebdd46ab6251e02b24</anchor>
      <arglist>(PinName pin, float vref=1.1f, adc_atten_t atten=ADC_ATTEN_DB_12)</arglist>
    </member>
    <member kind="function">
      <type>float</type>
      <name>ReadVoltage</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a07ab91335b5f2d64cb5326261c920e59</anchor>
      <arglist>(const int samples=1) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsValid</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a5f9848c8cb029853a9e76ac78163335a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>PinToAdcChannel</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>aede44606ca52954f7a14e025373340ce</anchor>
      <arglist>(PinName pin, adc_channel_t &amp;out) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>adc_channel_t</type>
      <name>_channel</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a09dc034a0ad30a3e5754f7329f3a331b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_vref</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>af15b3c59ed5c677c60750ba71f1a4a55</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>adc_bitwidth_t</type>
      <name>_width</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a1e71f6d967824dceb7c7234889a9017d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_valid</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>ada7989c4f45758701ac1f7cdc5066790</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>adc_cali_handle_t</type>
      <name>_cali</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>ade9ae5ddc295fc71ef1bafadd641c7a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static adc_oneshot_unit_handle_t</type>
      <name>_handle</name>
      <anchorfile>class_analog_in.html</anchorfile>
      <anchor>a98e165795d358555f6a639e5f632674a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Connectivity::APPortal</name>
    <filename>class_connectivity_1_1_a_p_portal.html</filename>
    <base>Base::Singleton&lt; APPortal &gt;</base>
    <base>Base::Driver</base>
    <member kind="enumeration">
      <type></type>
      <name>State</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ad0cfb8ea5b1b86473651df9dabc5c932</anchor>
      <arglist></arglist>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932aa5daf7f2ebbba4975d61dab1c40188c7">IDLE</enumvalue>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932afaee4ca3c30ee18148ce3ada37466498">INIT</enumvalue>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932aacefa4884b43f89ea6b69a8fed81f0d1">LISTENING_WIFI_CONFIG</enumvalue>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932afd6fc6e39adf315831c5a896e0293346">WIFI_CREDENTIALS_RECEIVED</enumvalue>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932a615a46af313786fc4e349f34118be111">STOP</enumvalue>
      <enumvalue file="class_connectivity_1_1_a_p_portal.html" anchor="ad0cfb8ea5b1b86473651df9dabc5c932abb1ca97ec761fc37101737ba0aa2e7c5">ERROR</enumvalue>
    </member>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a8a6e0d0b81ad697b9eb278355814c4b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Start</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ac5f479fa39dc0b353a17e6ede7372d9f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Stop</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ad0796b765fddfaf280aac44526421598</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ResetState</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a47f4e8e11583541980d866e9967db1dc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>State</type>
      <name>GetState</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a5f84f5a684ac7ccdc35006cdb1903eec</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>GetWifiCredentials</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ade257dc0de7e9d088b428863c4ea140c</anchor>
      <arglist>(std::string &amp;ssid, std::string &amp;password) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a4dea90946d61e0aad92c1ac523c4cc62</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>aebbb19848d5c947307c23496f0e1d1db</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a12cf99592ad307bb2e3e0116648f6eda</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>auto</type>
      <name>_Start</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a05ba68a102e061ce9f7de73f417f092a</anchor>
      <arglist>() -&gt; State</arglist>
    </member>
    <member kind="function" protection="private">
      <type>auto</type>
      <name>_Stop</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a362a1e2a9331299f3b3fa29652ad54db</anchor>
      <arglist>() -&gt; State</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>SetupHttpServer</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a8cc778ab9d8ce022f3cf929912138c4b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>StopHttpServer</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>af0282f65f7937dad66552dec7d713c1f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>EnableAPMode</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a437dba2034eff1768a5a62de6f01b43a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>DisableAPMode</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>adbf2f623c3b875b38d692b0328da9cd5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>APPortal</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ab7b2ac167b8d44de3848248661141e61</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~APPortal</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a7e5b97256b14ca7c9656f0550f2f90da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>APPortal</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a64ba6162d2b274cd89f28f692766e876</anchor>
      <arglist>(const APPortal &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>APPortal &amp;</type>
      <name>operator=</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a31a74e2737747e6c8d12498ca85424ae</anchor>
      <arglist>(const APPortal &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static esp_err_t</type>
      <name>HandleGetRoot</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a15d72bfaa1df9851dfa52c6e99cb70a7</anchor>
      <arglist>(httpd_req_t *req)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static esp_err_t</type>
      <name>HandlePostCredentials</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a8718a26b2a74d38017367685d1c4aeb4</anchor>
      <arglist>(httpd_req_t *req)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static esp_err_t</type>
      <name>HandleGetWifiNetworks</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a67582706baae53d9ea9560707f2e8df4</anchor>
      <arglist>(httpd_req_t *req)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static esp_err_t</type>
      <name>HandleGetStatus</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a2a4378f376e023319a069eb768a25263</anchor>
      <arglist>(httpd_req_t *req)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>State</type>
      <name>_state</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ac00acd9bf859aff7591e5cf649b89589</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>httpd_handle_t</type>
      <name>_httpServer</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ab6b06286c9f802663f30feaa3d67c21c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>esp_netif_t *</type>
      <name>_netif</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a288f6c2206787e37081bc7705991f63a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_configuredSsid</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a63e3ca42c955cd94d1d6781908de5b08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_configuredPassword</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>af874aab6b0c5c10ea4a61ad4a6d9bda7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>AP_SSID</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>ac81324b421b627e896eef1c6b953de2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>AP_PASSWORD</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a4dfb28de39624ba7671b293f7c346ed2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>AP_IP</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a4baed3a71d15cb62e768617b7d70b676</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint16_t</type>
      <name>HTTP_PORT</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a281561e22a1cb5d0177f3a2f8d47b7db</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; APPortal &gt;</name>
      <anchorfile>class_connectivity_1_1_a_p_portal.html</anchorfile>
      <anchor>a0797f5a8f1ad1d3ecda8d2f6476aa9e0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AsyncWorker</name>
    <filename>class_async_worker.html</filename>
    <member kind="typedef">
      <type>std::function&lt; void()&gt;</type>
      <name>WorkerMethodCallback</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a1046c57ded4b3c472d1d3682d2944c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AsyncWorker</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a64bec9576f9d624275a206452eb6e837</anchor>
      <arglist>(const char *name, uint32_t stackSize=2048, UBaseType_t priority=5)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AsyncWorker</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a938bab406fd103cd520d0c551b2088ba</anchor>
      <arglist>(const AsyncWorker &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>AsyncWorker &amp;</type>
      <name>operator=</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>ab740efab3350667c116432a8aa2074c7</anchor>
      <arglist>(const AsyncWorker &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Start</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a7bf3aa769be23a12714bbc7e302a9b50</anchor>
      <arglist>(WorkerMethodCallback workFn)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsBusy</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a9a650fca74868e1b8ea682046f8b74ea</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static void</type>
      <name>StaticEntryStub</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>aac23219cfdf0fc1c1be3074308985744</anchor>
      <arglist>(void *arg)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>const char *</type>
      <name>_name</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a16d966f364eb0cb8b64615e3f5cd5dec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint32_t</type>
      <name>_stackSize</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a46af3626cf4c22e2410c32e808b0cc2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>UBaseType_t</type>
      <name>_priority</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a53b2fe13ce150432d036e8b01fac2f5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TaskHandle_t</type>
      <name>_taskHandle</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a93ee6a8328c19dfd5dea3b768831f1cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>WorkerMethodCallback</type>
      <name>_workFn</name>
      <anchorfile>class_async_worker.html</anchorfile>
      <anchor>a600c6e6a5ab47cb45b307a6883026598</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Comms::ClientAttributesPayload</name>
    <filename>class_comms_1_1_client_attributes_payload.html</filename>
    <member kind="function">
      <type></type>
      <name>ClientAttributesPayload</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a81bab1ce855ee66d43d6e7cb0c79eb1e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>ToJsonString</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a25bafe0e8a0500bd56398d9ab9e46d1b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_timezone</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a2311199f714b7c1afef6e6f488c1eb69</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_minTemp</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a0c31f2bc4ad67ecc84941fec317a1c1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_minEnabled</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>aa6214457f7e0a02b1fdc8b047f4fff37</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_maxTemp</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a59532a528ed4ac6e280c90eb3c0b3914</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_maxEnabled</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a0046b2e4fe2e94a18d142f85bd00d28f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_minTds</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a6d8fc7ff0b717f819936885f5b0f0474</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_tdsMinEnabled</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a415a62795c73215f09b84c9cc3c8028d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_maxTds</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a136e199c1de23529613d8d5383f1e9c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_tdsMaxEnabled</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a5330d73f6c537952f2989255fef02a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Services::FeeddingScheduleList</type>
      <name>_scheduleList</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a3974a0c5f37534e4e9697486c13ad80e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_wifiSsid</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a295f467956e0e3821603323a879507cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int8_t</type>
      <name>_wifiRssi</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>a2903d85dceb1c152dfc702effe93c396</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_deviceTime</name>
      <anchorfile>class_comms_1_1_client_attributes_payload.html</anchorfile>
      <anchor>aa8607f0deb395527cc726a595e352c01</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Utils::DateTime</name>
    <filename>class_utils_1_1_date_time.html</filename>
    <member kind="function">
      <type></type>
      <name>DateTime</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>ad0365a214909de0c90e5540442fc6150</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DateTime</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a6da78499e1d659ac91c2660b20581666</anchor>
      <arglist>(uint8_t hour, uint8_t minute, uint8_t second)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DateTime</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>affa6fff16a707f7b8e00164458370514</anchor>
      <arglist>(uint32_t secondsOfDay)</arglist>
    </member>
    <member kind="function">
      <type>uint32_t</type>
      <name>ToSecondsOfDay</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>aad3caccc029ad6431ecc6f2f12eb051a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>uint32_t</type>
      <name>ToMinutesOfDay</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a1af40b715d6aade2d06aa63b8635d8c2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>ToString</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>ad844612ad7ed2f03fc17ccc0507a7faa</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Set</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a023317fdc3cafd1cc743b51b65dd601b</anchor>
      <arglist>(uint8_t hour, uint8_t minute, uint8_t second)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>GetHour</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a60573425d483a2103f979ebfb1f1021f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>GetMinute</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a0374fa5388f44beaadc516bfa91098f3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>GetSecond</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a8c7ae62fdd5f7b1c474e3b1ff0ec52cb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a95664d73dad651b3fb5c71ef38b3c41f</anchor>
      <arglist>(const DateTime &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a54584c93b2643f47f45a17d412f5d521</anchor>
      <arglist>(const DateTime &amp;other) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint8_t</type>
      <name>_hour</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>aaac68ab831a26ebb83716b91f1cfa69c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint8_t</type>
      <name>_minute</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>a2c24308756a29b02837d24d379002ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint8_t</type>
      <name>_second</name>
      <anchorfile>class_utils_1_1_date_time.html</anchorfile>
      <anchor>af05df1a52bcf82375a9b2c27c691ad3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Delay</name>
    <filename>class_delay.html</filename>
    <member kind="function">
      <type></type>
      <name>Delay</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>a6584fd4f8d46f71b09756b4156995e16</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Delay</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>a45a8ae7a4f064511241ba3a0b193064f</anchor>
      <arglist>(uint32_t interval_ms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Start</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>a3447c45d5aefd02f66bf67bb06934747</anchor>
      <arglist>(uint32_t interval_ms)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>HasFinished</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>a3e008e727d50235c8364f5b5af2a5105</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint64_t</type>
      <name>_startTime</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>a05a393bdd6d6e46eed4a7879c73e10f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint64_t</type>
      <name>_interval</name>
      <anchorfile>class_delay.html</anchorfile>
      <anchor>ac15df4f0b6266192d7fc76dda32258e2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::DeleteFeedingScheduleHandler</name>
    <filename>class_handlers_1_1_delete_feeding_schedule_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_delete_feeding_schedule_handler.html</anchorfile>
      <anchor>a904caa1bb96bc8c0610a0f64d17a370d</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_delete_feeding_schedule_handler.html</anchorfile>
      <anchor>a03c1bbfd69f488262da5ac87389bd0bd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DigitalInOut</name>
    <filename>class_digital_in_out.html</filename>
    <member kind="enumeration">
      <type></type>
      <name>PinMode</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982a7e89dba44fc257db349156093718206d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OUTPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982aa0555881d76901d3441b8711a88e76d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INPUT_OUTPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982a12a5740f8fced3dc844785deeb4383d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982a7e89dba44fc257db349156093718206d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OUTPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982aa0555881d76901d3441b8711a88e76d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INPUT_OUTPUT_MODE</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a7756405060ef1a62957346ba262f9982a12a5740f8fced3dc844785deeb4383d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DigitalInOut</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>ace822972df3207417b03db82b49987eb</anchor>
      <arglist>(PinName pin, PinMode mode, int value=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Write</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>afc0be918182176570e6d514ef38dc8d5</anchor>
      <arglist>(int value)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>Read</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a63a350d5166afc7545dd073b17b12bd7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Toggle</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a098675029fc80906fa4665ce1937a627</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>gpio_num_t</type>
      <name>_pin</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>ac56c2648f01c7816fe368893de41d469</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>PinMode</type>
      <name>_mode</name>
      <anchorfile>class_digital_in_out.html</anchorfile>
      <anchor>a6d36be5653e4eb0c704f3f873c904429</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Base::Driver</name>
    <filename>class_base_1_1_driver.html</filename>
    <base>Base::Module</base>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Driver</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>ab43c0e1d91e15b06acf12a445c49d1db</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Driver</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>a2964c47b2c392668631ff409ed6424e5</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Driver</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>a123682376081d5eeca5d44c79ff47017</anchor>
      <arglist>(const Driver &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Driver &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>a62c01450a394a254deef71c6dfbc3110</anchor>
      <arglist>(const Driver &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Driver</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>aaffceaf2d65602d34729da8fda5a4458</anchor>
      <arglist>(Driver &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Driver &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_driver.html</anchorfile>
      <anchor>a508f8d804b0d9e588f0a2ad8381206c7</anchor>
      <arglist>(Driver &amp;&amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Services::EepromMemory</name>
    <filename>class_services_1_1_eeprom_memory.html</filename>
    <base>Base::Singleton&lt; EepromMemory &gt;</base>
    <base>Base::Driver</base>
    <member kind="function">
      <type>bool</type>
      <name>WriteBytes</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a64c87bc87a42920fc97339bba5dcac0a</anchor>
      <arglist>(uint16_t address, const uint8_t *data, size_t length)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ReadBytes</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a1122771c3fb98bdbba3ff018cc078f29</anchor>
      <arglist>(uint16_t address, uint8_t *buffer, size_t length)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>afcff1cbd6609d8202c23e0ba4c09fffa</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a44a74ab77fab43176175235588065542</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a40ff1ac615793203ce83992065d50b2a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>WritePageInternal</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a1b088b2e6b080840d4f4c5c51e99fb68</anchor>
      <arglist>(uint16_t pageAddress, const uint8_t *data, size_t length)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>EepromMemory</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a08cdf578a1d1d5343b9779aa64e85fbf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~EepromMemory</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>aaf292a384a72d8f514372dc8370f9c15</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>EepromMemory</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>aa384497be5c57f033ea23f0634a7ac05</anchor>
      <arglist>(const EepromMemory &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>EepromMemory &amp;</type>
      <name>operator=</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a04eddd373a761a16ee9300bfc3d3794d</anchor>
      <arglist>(const EepromMemory &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>I2C</type>
      <name>_i2c</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>ab589d286429a8f60f433ea68a5cf9764</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr size_t</type>
      <name>EEPROM_SIZE_BYTES</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>af5a4dbfd908dc97ae266450a547846ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr size_t</type>
      <name>BYTES_PER_PAGE</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>af219caeeaffa6b3c9e84da594c0578b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr size_t</type>
      <name>NUM_PAGES</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>aa2c034906095d5d769135c31d3f2e353</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr size_t</type>
      <name>ENDL_CHAR</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a5da3736f6cc095f48d242d9bff411f5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; EepromMemory &gt;</name>
      <anchorfile>class_services_1_1_eeprom_memory.html</anchorfile>
      <anchor>a8cf1f14a57cf786a67387516ac3e1a05</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::FactoryResetHandler</name>
    <filename>class_handlers_1_1_factory_reset_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_factory_reset_handler.html</anchorfile>
      <anchor>a61c00da001bdbb97d4179c6b0926312a</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_factory_reset_handler.html</anchorfile>
      <anchor>a5870ca5047d5d883102627d1b294362c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Managers::FoodFeeder::FeederStatus</name>
    <filename>struct_managers_1_1_food_feeder_1_1_feeder_status.html</filename>
    <member kind="variable">
      <type>Utils::DateTime</type>
      <name>nextFeedTime</name>
      <anchorfile>struct_managers_1_1_food_feeder_1_1_feeder_status.html</anchorfile>
      <anchor>ab05856325d35f9f77c255477235580bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>nextFeedDoses</name>
      <anchorfile>struct_managers_1_1_food_feeder_1_1_feeder_status.html</anchorfile>
      <anchor>aad00128dbd3ac3d9383c1ccb7703bbfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>remainingDosesToday</name>
      <anchorfile>struct_managers_1_1_food_feeder_1_1_feeder_status.html</anchorfile>
      <anchor>ab38adab6a4b1c714d27daf254853b3eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>totalPerDay</name>
      <anchorfile>struct_managers_1_1_food_feeder_1_1_feeder_status.html</anchorfile>
      <anchor>a8ac48df98b9897e93cc859588eaa6600</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Services::FeedingScheduleEntry</name>
    <filename>struct_services_1_1_feeding_schedule_entry.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>struct_services_1_1_feeding_schedule_entry.html</anchorfile>
      <anchor>acb3764c801fc13a7cf4b6e3d65bc8097</anchor>
      <arglist>(const FeedingScheduleEntry &amp;other) const</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>_min</name>
      <anchorfile>struct_services_1_1_feeding_schedule_entry.html</anchorfile>
      <anchor>aa31460a99b5cffe3f43da5238c9a131b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>_id</name>
      <anchorfile>struct_services_1_1_feeding_schedule_entry.html</anchorfile>
      <anchor>a5b97b4185159a1bba76b97fc8ace7e3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>_dose</name>
      <anchorfile>struct_services_1_1_feeding_schedule_entry.html</anchorfile>
      <anchor>a8330a371ad364e445191f4b78c8c2f29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>_enabled</name>
      <anchorfile>struct_services_1_1_feeding_schedule_entry.html</anchorfile>
      <anchor>a599ed4b7d7a47de5a7acc04981ac1d1f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::FeedNowHandler</name>
    <filename>class_handlers_1_1_feed_now_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_feed_now_handler.html</anchorfile>
      <anchor>aa73f7cd1e16c85d5493094b3ebfbee46</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_feed_now_handler.html</anchorfile>
      <anchor>ad54777c8c789f9a24931204c5fc1722c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Managers::FoodFeeder</name>
    <filename>class_managers_1_1_food_feeder.html</filename>
    <base>Base::Singleton&lt; FoodFeeder &gt;</base>
    <base>Base::Manager</base>
    <class kind="struct">Managers::FoodFeeder::FeederStatus</class>
    <member kind="function">
      <type>auto</type>
      <name>Feed</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a765bc18844e32e6e971814c0f768c5ae</anchor>
      <arglist>(int dose) -&gt; Result</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>AddFeedingScheduleEntry</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a3ea07fd4a21b6599a2eb8adce48b6c9c</anchor>
      <arglist>(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -&gt; Result</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>DeleteFeedingScheduleEntry</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a44219699ff0cc679569ec8ea377188ef</anchor>
      <arglist>(int slotIndex) -&gt; Result</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetFeederStatus</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a14ab540737a81032f779ea6c3ce294b8</anchor>
      <arglist>() const -&gt; FeederStatus</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a92f38273310d7fac63f4ccdea39faf5a</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a20f59807e520a6f7bf20f99b9645a44e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a9d9f2b341997898e15176b3b07440b29</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>PerformAsyncFeedingSequence</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a22d1b22f76bec48a2b7899d14b6d8130</anchor>
      <arglist>(int dose)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>FoodFeeder</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>ae076a4be87f585ee81c8942838c6d27a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~FoodFeeder</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a452a4aa6f2ac59b63ac48bcf8d9a2d5f</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>FoodFeeder</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a2cb45f3d16a984858cd51fb569e14afa</anchor>
      <arglist>(const FoodFeeder &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>FoodFeeder &amp;</type>
      <name>operator=</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a72753d094e24b1edb44a8a403947b25a</anchor>
      <arglist>(const FoodFeeder &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::Servo *</type>
      <name>_servo</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a6318c8272db4a3c999d892eee18dc3f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>AsyncWorker</type>
      <name>_feedingTask</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a1843584c24879d6feeb2b98e1e15bed7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_lastFeedTime</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a2ef5ac738639ceb6197e31eb5cfedadf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>MAX_FEEDING_SCHECULES</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>afdd58a285530fa52a68cef42cd817454</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>MINUTES_IN_A_DAY</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a61cfacbb3e7db83aa9eb1fd158e09699</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>MIN_FEED_DOSE</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a233c05326414136edf37f5aa784a36d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>MAX_FEED_DOSE</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>aa13ab815da82ae0eec247c9c757ad788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const float</type>
      <name>FEEDER_OPEN_ANGLE</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a09ed5fa92306147d7da8e004b29cadd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const float</type>
      <name>FEEDER_CLOSED_ANGLE</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a7f205b88b619e96ba1c857ead775452f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>FEEDER_MOVE_TIME_MS</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a41caf1fa7abae1bab6ce88a040c5de7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const int</type>
      <name>FEEDER_WAIT_TIME_MS</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a918356e17dc88ed8fd6480e371184bf6</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; FoodFeeder &gt;</name>
      <anchorfile>class_managers_1_1_food_feeder.html</anchorfile>
      <anchor>a604f21a6fa48189c2abe0a747c3323d1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Drivers::GraphicDisplay</name>
    <filename>class_drivers_1_1_graphic_display.html</filename>
    <base>Base::Singleton&lt; GraphicDisplay &gt;</base>
    <base>Base::Driver</base>
    <class kind="class">Drivers::GraphicDisplay::UIElement</class>
    <member kind="typedef">
      <type>std::function&lt; void()&gt;</type>
      <name>TouchCallback</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a8e291b4ae871354f199dbdf44bf8deec</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetOnDoubleClickAction</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>acb14490fe3843beebb12e23cd5d5a632</anchor>
      <arglist>(TouchCallback callback)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetOnLongPressAction</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ab81bd66d05fd6dab53432a96ea8c913e</anchor>
      <arglist>(TouchCallback callback)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetBrightness</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a1773b9410510a2bc8955bb2ee67a025e</anchor>
      <arglist>(uint8_t brightness)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr int</type>
      <name>DISP_H_RES</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>adaa4291ec869ac39bd979556d0e285e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr int</type>
      <name>DISP_V_RES</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a2936f0946c92735bb0308864f76f4a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>af414e38f6b0ba3599ecbc6b3d61b2ad5</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a5d84fec06d5ac3d8c4e8606e766f9c29</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a2a20faca94d534d8646b44ad3c457dc8</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>SetupTouchDetection</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ac43e447a89d910142ac5dc279e9d768c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>GraphicDisplay</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a3da75688764208e400c91c49679c88f1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~GraphicDisplay</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ab265882d411b326da9bc46f36f45dc08</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>GraphicDisplay</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>abe9c5e9e4c15a873df655aae3ad8dbf4</anchor>
      <arglist>(const GraphicDisplay &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>GraphicDisplay &amp;</type>
      <name>operator=</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ab904cead4bcbf3b0efe22261d97399ae</anchor>
      <arglist>(const GraphicDisplay &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static void</type>
      <name>OnTouchTimer</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>aecd1bd71a996506be461f091cfcdf986</anchor>
      <arglist>(lv_timer_t *timer)</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static void</type>
      <name>OnTouchEventCallback</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a3d771f6433029c2d51ee034f05f3af79</anchor>
      <arglist>(lv_event_t *e)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_misoPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>aa366eb5bdb797e97040510d462a1f744</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_mosiPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a2d4f0a8bfdb31fe55f3bcac78fb59119</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_clkPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a381f43a35269ecf22c3dda6e85eeb873</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_csPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a3e0202bf1312d3a7a87edbd3d0d370f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_dcPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>afdc427bbe55850ce5e9f48dfa102d9e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_rstPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ada49504e2670def20fe8d51e305c3f21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_touchCsPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a9bcff6b806e809fb184c24690c676f1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_touchIrqPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a21f4ccc5c1cefd8c120b0f1197f707f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>PwmOut</type>
      <name>_bklPin</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a611993b3f47749505d377842d9e286d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TouchCallback</type>
      <name>_onDoubleClickAction</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a1cce0e10e908bfefef9aa31ba01277cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TouchCallback</type>
      <name>_onLongPressAction</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a2313fa9bf239e3c59c48fd5273f89ebf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint32_t</type>
      <name>_lastTapTime</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a96fbcedf73a838b9695744c54c8eac14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>esp_lcd_panel_handle_t</type>
      <name>_panel_handle</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>aad950e3cbd15e5f648231b5bb8fa9e21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>esp_lcd_touch_handle_t</type>
      <name>_tp_handle</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a3b810209d55044d1c81a4787b5799815</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>lv_display_t *</type>
      <name>_lvgl_disp</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a0f094539bd6b9af41457388e7d212485</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_valid</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>ab1558d7f80f8c3efbbbab16b845cad39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>DISP_SPI_HOST</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a1045e0b40afb84d3df8f8cafdd2d71c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint32_t</type>
      <name>DOUBLE_TAP_MS</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a4137e842ca26b1b9f092b01a7aa97532</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; GraphicDisplay &gt;</name>
      <anchorfile>class_drivers_1_1_graphic_display.html</anchorfile>
      <anchor>a054ba121003aa75ee6343f9f5fa03aa1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::GuardianProxy</name>
    <filename>class_core_1_1_guardian_proxy.html</filename>
    <base>Base::Singleton&lt; GuardianProxy &gt;</base>
    <base>Base::Module</base>
    <base>Core::IStorageService</base>
    <base>Core::IFoodFeeder</base>
    <base>Core::INetworkController</base>
    <base>Core::IPowerController</base>
    <base>Core::IRealTimeClock</base>
    <base>Core::IUserInterface</base>
    <base>Core::IWaterMonitor</base>
    <member kind="function">
      <type>auto</type>
      <name>Feed</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>aef6c8e6ff08d0ee7cb9a734f4cc0f00f</anchor>
      <arglist>(int dose) -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>AddFeedingScheduleEntry</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>af3f62fdb053742a3728484a17747c7ca</anchor>
      <arglist>(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>DeleteFeedingScheduleEntry</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a2cd5d05f53bfa7199dc18112ac7ae59f</anchor>
      <arglist>(int slotIndex) -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetFeederStatus</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a9d92798b6829f073668dbd87e0853242</anchor>
      <arglist>() const -&gt; Managers::FoodFeeder::FeederStatus override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>ActivateApMode</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a4f30c6de7b91238bf2a2e21d1dadf80f</anchor>
      <arglist>() -&gt; void override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsWifiConnected</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a63242e189c06d1974e6c0ac27949e3d8</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetWifiSsid</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a3447d9e7acfa6c06809f17b27ffde4a9</anchor>
      <arglist>() const -&gt; std::string override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetWifiRssi</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a27e71fcf62ddf12600f1e3696c6daa54</anchor>
      <arglist>() const -&gt; int8_t override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsMqttConnected</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>adaf0c9ec79c4a470b8731dcc80c6e789</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsApPortalActive</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>aa73e472c8a1e720e7fadc013da409020</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SyncDevice</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a323f8765dfbe82d1de697fb4c424f03e</anchor>
      <arglist>() -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetCurrentMode</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a4648ad577bf79ea47ed3b6d556fb2b25</anchor>
      <arglist>() -&gt; Services::PowerController::Mode override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetBatteryLevel</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ab7a6d7cea18df774f6f003d48b47e937</anchor>
      <arglist>() -&gt; Services::PowerController::BatteryLevel override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetDateTime</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a3d9cef672b1df8d8e5660db2e688b1c4</anchor>
      <arglist>(Utils::DateTime &amp;time) const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsTimeSynced</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a51c3ac55c5cad8546caf534ed414259b</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>InitTimeSync</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a78980839a2a2f85f098d3591a7dc150a</anchor>
      <arglist>(const char *timezone=nullptr) const -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SaveWifiCredentialsInStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ab90290364c34c1dabe6fefe6d489c9c2</anchor>
      <arglist>(const std::string &amp;ssid, const std::string &amp;password) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetWifiSsidFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a13fb90a79eb64201e6ea1ce14a7f61ac</anchor>
      <arglist>() const -&gt; std::string override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetWifiPasswordFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a8ccf6b3c09b11764410175570a0a6747</anchor>
      <arglist>() const -&gt; std::string override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SaveTimezoneInStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>abebc864598f468f31f3ef0556670a835</anchor>
      <arglist>(const std::string &amp;tz) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTimezoneFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a12b935970aeb5a22976b81f31612e64f</anchor>
      <arglist>() const -&gt; std::string override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SaveTempLimitsInStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>acb8020bd358870b2c5e17e3e115f5e4a</anchor>
      <arglist>(float minTemp, bool minEnabled, float maxTemp, bool maxEnabled) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTempLimitsFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a5fb048777ac6741b4d4f50e110f4607a</anchor>
      <arglist>(float &amp;minTemp, bool &amp;minEnabled, float &amp;maxTemp, bool &amp;maxEnabled) const -&gt; void override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SaveTdsLimitsInStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>aa954bec645e764416351d7e3e04c1bdd</anchor>
      <arglist>(int minTds, bool minEnabled, int maxTds, bool maxEnabled) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTdsLimitsFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ad4b17eec1cf7fc7bbd9c1725f5b6fa6b</anchor>
      <arglist>(int &amp;minTds, bool &amp;minEnabled, int &amp;maxTds, bool &amp;maxEnabled) const -&gt; void override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SaveFeedingScheduleInStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a91564dfc7e0206e66a2eb5bae5fee0ce</anchor>
      <arglist>(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetFeedingScheduleFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a8fb27d1644e66355a5987ff03e186fc5</anchor>
      <arglist>() const -&gt; Services::FeeddingScheduleList override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>RemoveFeedingScheduleFromStorage</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a94f64e43da1e01c7d873bb9cc9c487f4</anchor>
      <arglist>(const int slotIndex) -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>FactoryReset</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>af494b8aed29bda3ee99f6701634008e9</anchor>
      <arglist>() -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>UpdateFeedingStatusIndicator</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>afb531792d89c0059473915dbe637886c</anchor>
      <arglist>(bool isFeeding) override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTdsReading</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a4eeccae4f941bfa709fccf54cafe0399</anchor>
      <arglist>() const -&gt; int override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTemperatureReading</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a5a1aa7cb3d13e9ab6ee546978e7fcab0</anchor>
      <arglist>() const -&gt; float override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SetTemperatureLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a6ff2d4fbef329035ed52c26db15eab1c</anchor>
      <arglist>(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled) -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTemperatureLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a082aa636a2f015ff43603f379d9ba6d8</anchor>
      <arglist>(float &amp;minTemp, bool &amp;isMinLimitEnabled, float &amp;maxTemp, bool &amp;isMaxLimitEnabled) const -&gt; void override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsTemperatureOutOfLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>aa95619608523a73281cfb25c851f2a3a</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>SetTdsLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a1d55a8a2b7128106c9bfc5d4d410fd3e</anchor>
      <arglist>(const int minTds, const bool isMinLimitEnabled, const int maxTds, const bool isMaxLimitEnabled) -&gt; Result override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetTdsLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a6bb1deba0f2c9b8e7de0463fcc6e0445</anchor>
      <arglist>(int &amp;minTds, bool &amp;isMinLimitEnabled, int &amp;maxTds, bool &amp;isMaxLimitEnabled) const -&gt; void override</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>IsTdsOutOfLimits</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>aa01254e30290e57ff41d53116595430b</anchor>
      <arglist>() const -&gt; bool override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a49b5086a7ed3c8e43f07ce69fb14777e</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a36ae047c0f80d4338169c67538d5cf1a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a73babda6360e57b41811c5af3629ee05</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>GuardianProxy</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ac2fc8192f614e1c7b0174a5c8321a86a</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~GuardianProxy</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>a7f8c9266acb9965fd078ef56215beec8</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>GuardianProxy</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>adc7dde2846eb2811bd65b50e436abcb7</anchor>
      <arglist>(const GuardianProxy &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>GuardianProxy &amp;</type>
      <name>operator=</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ab32cc9defebc8f828954d59a3a7d0612</anchor>
      <arglist>(const GuardianProxy &amp;)=delete</arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; GuardianProxy &gt;</name>
      <anchorfile>class_core_1_1_guardian_proxy.html</anchorfile>
      <anchor>ad02caf408071be876287dbea4edf4e72</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>I2C</name>
    <filename>class_i2_c.html</filename>
    <member kind="function">
      <type></type>
      <name>I2C</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>af18ecf81ec83cab565a5f2810e919813</anchor>
      <arglist>(PinName sda, PinName scl, uint8_t addr7bit, i2c_port_num_t port=I2C_NUM_0, uint32_t freqHz=100000)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~I2C</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>afaad09fa9bdd23623bddbdcd7585a9fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Write</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>afdf9edbe8b8540fdf5622324f982e127</anchor>
      <arglist>(const uint8_t *data, size_t len)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Read</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>ac2ce81656af10bbf2e2c85db2ed4229a</anchor>
      <arglist>(uint8_t *data, size_t len)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>WriteRead</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>a4f6286d04145f391f8af59fd128e9a38</anchor>
      <arglist>(const uint8_t *txBuffer, size_t txLen, uint8_t *rxBuffer, size_t rxLen)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsValid</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>a10f608ff7be2af2b83163cbc7dc0898c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>i2c_port_num_t</type>
      <name>_port</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>a06d149b4baf33a175ce7884bb6795dad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>i2c_master_dev_handle_t</type>
      <name>_dev</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>ada39f0c0760775df38a52135a1711927</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_valid</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>a834359048a12719e734b74fc40511c38</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>SemaphoreHandle_t</type>
      <name>_mutex</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>acbee2f08f45fe6e8a1fb1ff5136db8c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static i2c_master_bus_handle_t</type>
      <name>_busHandles</name>
      <anchorfile>class_i2_c.html</anchorfile>
      <anchor>aee5e090c673c14de9bae25774d20d39d</anchor>
      <arglist>[I2C_NUM_MAX]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IFoodFeeder</name>
    <filename>class_core_1_1_i_food_feeder.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>Feed</name>
      <anchorfile>class_core_1_1_i_food_feeder.html</anchorfile>
      <anchor>aac03b0519329dc37c233958c9f10597f</anchor>
      <arglist>(int dose) -&gt; Result=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>AddFeedingScheduleEntry</name>
      <anchorfile>class_core_1_1_i_food_feeder.html</anchorfile>
      <anchor>ac5ff6983254b9e903fb57ffae48a5b51</anchor>
      <arglist>(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -&gt; Result=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>DeleteFeedingScheduleEntry</name>
      <anchorfile>class_core_1_1_i_food_feeder.html</anchorfile>
      <anchor>a026fb303de5b27d728f33c94f95035b2</anchor>
      <arglist>(int slotIndex) -&gt; Result=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetFeederStatus</name>
      <anchorfile>class_core_1_1_i_food_feeder.html</anchorfile>
      <anchor>ad622834a55832a1a33e1d9c905d393f1</anchor>
      <arglist>() const -&gt; Managers::FoodFeeder::FeederStatus=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::INetworkController</name>
    <filename>class_core_1_1_i_network_controller.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>ActivateApMode</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>a262cbe91bc76f2049ca2ceb037c553f2</anchor>
      <arglist>() -&gt; void=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsWifiConnected</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>aec92da218f920dba4d06b1658d23acd3</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetWifiSsid</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>a86800941c2bd328e5ca6d0af78903461</anchor>
      <arglist>() const -&gt; std::string=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetWifiRssi</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>acfcec0627cf9abf6665d18d0c880d117</anchor>
      <arglist>() const -&gt; int8_t=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsMqttConnected</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>a032eeb8c16a2daf4a4ee6d3bc80cb7c7</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsApPortalActive</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>afcfd013cdb415b20ad92ea819c7a68be</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SyncDevice</name>
      <anchorfile>class_core_1_1_i_network_controller.html</anchorfile>
      <anchor>a501cde58973e48df2daf1d32292120a2</anchor>
      <arglist>() -&gt; Result=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IPowerController</name>
    <filename>class_core_1_1_i_power_controller.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetCurrentMode</name>
      <anchorfile>class_core_1_1_i_power_controller.html</anchorfile>
      <anchor>a5eb9df556705d87744490b60484145b6</anchor>
      <arglist>() -&gt; Services::PowerController::Mode=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetBatteryLevel</name>
      <anchorfile>class_core_1_1_i_power_controller.html</anchorfile>
      <anchor>a639d1d5d3974a4089b88bc739db015ea</anchor>
      <arglist>() -&gt; Services::PowerController::BatteryLevel=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IRealTimeClock</name>
    <filename>class_core_1_1_i_real_time_clock.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetDateTime</name>
      <anchorfile>class_core_1_1_i_real_time_clock.html</anchorfile>
      <anchor>aebce1551bdfe1b04fdd85f5ed26ee03f</anchor>
      <arglist>(Utils::DateTime &amp;time) const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsTimeSynced</name>
      <anchorfile>class_core_1_1_i_real_time_clock.html</anchorfile>
      <anchor>a5febd713247719ce8778aff4cdbbe14d</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>InitTimeSync</name>
      <anchorfile>class_core_1_1_i_real_time_clock.html</anchorfile>
      <anchor>a3b7141f322be8da56c40a28bcc09d42c</anchor>
      <arglist>(const char *timezone=nullptr) const -&gt; Result=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::IRpcHandler</name>
    <filename>class_handlers_1_1_i_rpc_handler.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IRpcHandler</name>
      <anchorfile>class_handlers_1_1_i_rpc_handler.html</anchorfile>
      <anchor>ab00ac97365484812792b7ec81655d29d</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_i_rpc_handler.html</anchorfile>
      <anchor>a68ecc1084ced0cda711c6ca982f06092</anchor>
      <arglist>(const std::string &amp;payload)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IStorageService</name>
    <filename>class_core_1_1_i_storage_service.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>SaveWifiCredentialsInStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a44eecbcd31ab420337d75eb4d47f7d4b</anchor>
      <arglist>(const std::string &amp;ssid, const std::string &amp;password)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>GetWifiSsidFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a764943c662bb40edc4efcdcfd939f558</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>GetWifiPasswordFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a89fb9256e52e6285c43c01e69aad087a</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>SaveTimezoneInStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a92076ed9f6cf093f342f01de458dc5b2</anchor>
      <arglist>(const std::string &amp;tz)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::string</type>
      <name>GetTimezoneFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>aba0388996b6fd9ea6796229272496b49</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SaveTempLimitsInStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a0b364201ce7681e48b5e20729c8de504</anchor>
      <arglist>(float minTemp, bool minEnabled, float maxTemp, bool maxEnabled) -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTempLimitsFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a96928e53ae5f6b5245926d1c5ba117f6</anchor>
      <arglist>(float &amp;minTemp, bool &amp;minEnabled, float &amp;maxTemp, bool &amp;maxEnabled) const -&gt; void=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SaveTdsLimitsInStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a73893816af15e425e6246f4d1a2530e1</anchor>
      <arglist>(int minTds, bool minEnabled, int maxTds, bool maxEnabled) -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTdsLimitsFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>aac66f31b2626b04d585cfa1ef0ce31c0</anchor>
      <arglist>(int &amp;minTds, bool &amp;minEnabled, int &amp;maxTds, bool &amp;maxEnabled) const -&gt; void=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SaveFeedingScheduleInStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>ae03f9ed2ff304dfd385c186171cb91fe</anchor>
      <arglist>(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled) -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetFeedingScheduleFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a5daf2ccb6a819a53af2b4a809279beba</anchor>
      <arglist>() const -&gt; Services::FeeddingScheduleList=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>RemoveFeedingScheduleFromStorage</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>a77c4aaf4e219fcd02889c6159dfa4c07</anchor>
      <arglist>(const int slotIndex) -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>FactoryReset</name>
      <anchorfile>class_core_1_1_i_storage_service.html</anchorfile>
      <anchor>aab5a7817c3db60be212002fd3e2dc5d1</anchor>
      <arglist>() -&gt; Result=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IUserInterface</name>
    <filename>class_core_1_1_i_user_interface.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>UpdateFeedingStatusIndicator</name>
      <anchorfile>class_core_1_1_i_user_interface.html</anchorfile>
      <anchor>a0bcd9b155bcb7eb235d0d6319b2a707b</anchor>
      <arglist>(bool isFeeding)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Core::IWaterMonitor</name>
    <filename>class_core_1_1_i_water_monitor.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTdsReading</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a000ebcd6b63b74acdbbcf05fd08a3857</anchor>
      <arglist>() const -&gt; int=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTemperatureReading</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a51d65ba093c0398c5c25555bb176ce08</anchor>
      <arglist>() const -&gt; float=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SetTemperatureLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>ad1b13f132016f11e32e59137e1dbba69</anchor>
      <arglist>(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled) -&gt; Result=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTemperatureLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a23086aa3dc68869e98bf51a7ea1bcd0f</anchor>
      <arglist>(float &amp;minTemp, bool &amp;isMinLimitEnabled, float &amp;maxTemp, bool &amp;isMaxLimitEnabled) const -&gt; void=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsTemperatureOutOfLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a6d4d26d8171991d4b52e422853b886d5</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>SetTdsLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a59673fed72b70644905645bfb2d9dcf6</anchor>
      <arglist>(const int minTds, const bool isMinLimitEnabled, const int maxTds, const bool isMaxLimitEnabled) -&gt; Result=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>GetTdsLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a15be337116d8ffcd53aafd82b9414718</anchor>
      <arglist>(int &amp;minTds, bool &amp;isMinLimitEnabled, int &amp;maxTds, bool &amp;isMaxLimitEnabled) const -&gt; void=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual auto</type>
      <name>IsTdsOutOfLimits</name>
      <anchorfile>class_core_1_1_i_water_monitor.html</anchorfile>
      <anchor>a7b5432123a6d0552d83c4f2dc4081b33</anchor>
      <arglist>() const -&gt; bool=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Utils::JsonPayloadParser</name>
    <filename>class_utils_1_1_json_payload_parser.html</filename>
    <member kind="function">
      <type></type>
      <name>JsonPayloadParser</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>af8192173a16052a1308b2ecd7f94ce91</anchor>
      <arglist>(const std::string &amp;payload)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsValid</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a3c8a7719f71b9c9753084ec712af39b8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>GetError</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a937aff9cd4e441c67e1dff286e51243b</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::optional&lt; std::string &gt;</type>
      <name>GetMethod</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>ab0aeb238682986cecd1a62b147b5b8ad</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::optional&lt; T &gt;</type>
      <name>GetValue</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a6c0d1b2498c81d45fbf83731b85ab2eb</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;parentKey=&quot;&quot;) const</arglist>
    </member>
    <member kind="function">
      <type>std::optional&lt; T &gt;</type>
      <name>GetParam</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a18d40190f8d3a637c636135aa8260b83</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Json</type>
      <name>_json</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a4e417a3b790fa28990cc0fa423861352</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_isValid</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>ad5cf933aff173a21844dc27a21dad38f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_errorMsg</name>
      <anchorfile>class_utils_1_1_json_payload_parser.html</anchorfile>
      <anchor>a138d88b9bb260b57adb2eca593eb9027</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Base::Manager</name>
    <filename>class_base_1_1_manager.html</filename>
    <base>Base::Module</base>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Manager</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a8c9a2be44e29c8fac4d246c41e1d9b23</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Update</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>aa4e5e119300e54cfa1b9fcb999eea816</anchor>
      <arglist>(int delayAfterMs=0)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Manager</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a303dddb5c95dbf7bd168c77f122c20ea</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>OnBatteryModeEnter</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a12f83b2360e02ba8dbe451aabcfb53fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>OnBatteryModeExit</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a82b1114596936e6b3f5036345a6c5300</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>_CheckBatteryModeChange</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>aaa44ee00c889255d7808afebb45b6a0f</anchor>
      <arglist>(bool &amp;enteredBatteryMode, bool &amp;exitedBatteryMode)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Manager</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>acc21940016ae296ecb7405fb25dba870</anchor>
      <arglist>(const Manager &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Manager &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>acea5a5537f1cb280ac15c93ab971a92e</anchor>
      <arglist>(const Manager &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Manager</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a046081e27376d34723fda5f235d5a7ad</anchor>
      <arglist>(Manager &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Manager &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a2dbc9108fa113c8a69ce867046cb2376</anchor>
      <arglist>(Manager &amp;&amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_lastBatteryMode</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>aa4fae8eed6b57ba9f5936096f1349af9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint64_t</type>
      <name>_batteryModeRecoveryEndUs</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a17920f7b10f33723be102b7d58bad179</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint32_t</type>
      <name>BATTERY_MODE_RECOVERY_MS</name>
      <anchorfile>class_base_1_1_manager.html</anchorfile>
      <anchor>a9db904e95fbef268acb005b325c8dafe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Services::MemoryConfigData</name>
    <filename>struct_services_1_1_memory_config_data.html</filename>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>struct_services_1_1_memory_config_data.html</anchorfile>
      <anchor>a636386ab9c52e8d73e53b629e8feeb76</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>CONFIG_FIELDS auto</type>
      <name>ToJson</name>
      <anchorfile>struct_services_1_1_memory_config_data.html</anchorfile>
      <anchor>a942c74c0f4b5f6295a3207cfc3921a01</anchor>
      <arglist>() const -&gt; std::string</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>FromJson</name>
      <anchorfile>struct_services_1_1_memory_config_data.html</anchorfile>
      <anchor>a44652a95c8aae3521c256c36843e07bd</anchor>
      <arglist>(const std::string &amp;jsonString) -&gt; bool</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Base::Module</name>
    <filename>class_base_1_1_module.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Module</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a77efdb2432eb3d4a838ec2619bc8d3ce</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Init</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a856d4f6ccf8f96235c1267c915422abd</anchor>
      <arglist>(int delayAfterMs=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Update</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>ab77873b8af53254bf6d0da5c35b916b7</anchor>
      <arglist>(int delayAfterMs=0)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Module</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a6d6e81bd1a575381ad42862275122bcf</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a15056609a354d6c3c02c5aa19e858ca7</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual bool</type>
      <name>OnInit</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a3e476ee110d2077932857f7e437ac353</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>OnUpdate</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a71aaf1f71fc61f897b5856894b9d0482</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Module</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a405112fca9b0375f771f378ec89a0ad2</anchor>
      <arglist>(const Module &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Module &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a5c869804457467eafd230442b22a86f3</anchor>
      <arglist>(const Module &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Module</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a91ca9d535b072157e98e804f7566eefd</anchor>
      <arglist>(Module &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Module &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_module.html</anchorfile>
      <anchor>a567714f37e1666df2949422036e8f0b3</anchor>
      <arglist>(Module &amp;&amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Connectivity::MqttClient</name>
    <filename>class_connectivity_1_1_mqtt_client.html</filename>
    <base>Base::Singleton&lt; MqttClient &gt;</base>
    <base>Base::Driver</base>
    <member kind="enumeration">
      <type></type>
      <name>State</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a0fa55d2fea208ccdd543bb5a5fe7ab44</anchor>
      <arglist></arglist>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44aa5daf7f2ebbba4975d61dab1c40188c7">IDLE</enumvalue>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44afaee4ca3c30ee18148ce3ada37466498">INIT</enumvalue>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44a9a14f95e151eec641316e7c784ce832d">CONNECTING</enumvalue>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44aa5afd6edd5336d91316964e493936858">CONNECTED</enumvalue>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44aad793e31fab5703fc5b990cf40f8a585">DISCONNECTING</enumvalue>
      <enumvalue file="class_connectivity_1_1_mqtt_client.html" anchor="a0fa55d2fea208ccdd543bb5a5fe7ab44abb1ca97ec761fc37101737ba0aa2e7c5">ERROR</enumvalue>
    </member>
    <member kind="typedef">
      <type>std::function&lt; void(const std::string &amp;topic, const std::string &amp;payload)&gt;</type>
      <name>MessageCallback</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>aa86d64106b8dd9b78a15478629f3413e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsConnected</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a403f3e0b21e5117c5b00ab4f12b54a57</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Start</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a0d6e18caa24a0aa28d4075340f79139a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Stop</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>ab4399a06e6a01783cb6be7188410b3d3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Publish</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a145ff3cde7d9d83b4f6b00a668af58be</anchor>
      <arglist>(const std::string &amp;topic, const std::string &amp;payload, int qos=1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Subscribe</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a82773f538dfb9152149786cfb9227b70</anchor>
      <arglist>(const std::string &amp;topic, MessageCallback cb=nullptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetMessageCallback</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>ab15942653ece85eaccd594ce69c79e4f</anchor>
      <arglist>(MessageCallback cb)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>abfadee1b9fd8201717a9d55f46d9fc37</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a290aa6dfcf29ea45935e367e5045053a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a347d6c04823e73fccba853a260f7069e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>auto</type>
      <name>_Start</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>af3dd7ccd6d8ef5b64fc22d042248ecdc</anchor>
      <arglist>() -&gt; State</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>_Stop</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>adb16605ad6574285ba1577d2bf2f35d4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>MqttClient</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a1d1c25af623cb18428700c716803825c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~MqttClient</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a7f7b933fab68a39f1ac8e8690b4611ab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>MqttClient</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a1ce3bd3e0ec924cf1f58a12229a1e53d</anchor>
      <arglist>(const MqttClient &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>MqttClient &amp;</type>
      <name>operator=</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a1a550d24ab0843a57eebea0fc3fcbaf9</anchor>
      <arglist>(const MqttClient &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static void</type>
      <name>EventHandler</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a4e2a57ce818413ccb10d1ca5be139c5f</anchor>
      <arglist>(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>State</type>
      <name>_state</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a374b8860d5dd8bfe9d1a4150d4e07d29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>esp_mqtt_client_handle_t</type>
      <name>_client</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>ac4fa073f1a69b8723177de40b01d7700</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_brokerUri</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>a3fa3757478f456c41082e3e34de757c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_username</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>ae83f6c536f10f63f473d11bb12432e88</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::atomic&lt; bool &gt;</type>
      <name>_connected</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>afffd19aa05c5e8dd6deb510c7978c9a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MessageCallback</type>
      <name>_globalCallback</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>ae93cbae7f7b2426419605409d274713e</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; MqttClient &gt;</name>
      <anchorfile>class_connectivity_1_1_mqtt_client.html</anchorfile>
      <anchor>af0788ba02b85a6402898c7772103d0b2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Managers::NetworkController</name>
    <filename>class_managers_1_1_network_controller.html</filename>
    <base>Base::Singleton&lt; NetworkController &gt;</base>
    <base>Base::Manager</base>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a8558caca59e4233dbd8acf3854c67df0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ActivateApMode</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a50f8d4e092721cdc984d826fc24a19a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsWiFiConnected</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a2ed93d170fedd8c924f4f4cd80e2e3f9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>GetWifiSsid</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a5fc56d7cacb8efee276e2bed6a8db23c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int8_t</type>
      <name>GetWifiRssi</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a4570f3746ad94683f73463361eb643ae</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsMqttClientConnected</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>ae533b34def2968f29300329222dfc9e1</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsApPortalActive</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>af4d3148647e90ecdbeb6adcf1056bbc9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>SyncDevice</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>af032bb0de44c7b1b018ce7944dc867dc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>abde16e82c108d3a0da17fc05c4af1346</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a574474a13926c5c0662bcbb51ffaaaff</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>aeecd72ff7e6e600639795989e18c4fbd</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnBatteryModeEnter</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a545dceac171b488fe5b4700991f1d55e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnBatteryModeExit</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a851c9af262ef450ba868de667669daed</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="enumeration" protection="private">
      <type></type>
      <name>State</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a684f7c3e5e8f2e862e78ff8ab8681172</anchor>
      <arglist></arglist>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172afaee4ca3c30ee18148ce3ada37466498">INIT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a908457bc56a02cebe788cfc07f87c56d">PRE_START_WIFI</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172abd4b33d9b8c9f3a8681694128f5575f2">START_WIFI</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172aae7fdcc5cd7b11e059ed00fcc609fa0b">WAITING_FOR_WIFI</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a56f533880a65a7275939fc3490609b4c">START_TIME_SYNC</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a58283e09301f1c98a0ee1cdf114b57c5">WAITING_FOR_TIME_SYNC</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172aded056c59581c7721a73fbf8c69080d9">START_MQTT_CLIENT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172ac3d6e5f2850b377474f21a14b7e29c5f">WAITING_FOR_MQTT_CLIENT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a732b224dc1a56650383e90585cf5f430">SETUP_MQTT_CLIENT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172aa5daf7f2ebbba4975d61dab1c40188c7">IDLE</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a75ce7af59a286bb8de8dd8f6d79a836d">SEND_TELEMETRY</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a528f92f202d7e93a80d3144838bf7649">PRE_START_ACCESS_POINT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172aca58124008fcf0f96741cb955a939745">START_ACCESS_POINT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a93e48037f2c52d04591b06915c4c4e59">WAITING_FOR_ACCESS_POINT</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172a615a46af313786fc4e349f34118be111">STOP</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172aa5b30f47f98f9326989795dc2887b0fa">NO_CONNECTIONS</enumvalue>
      <enumvalue file="class_managers_1_1_network_controller.html" anchor="a684f7c3e5e8f2e862e78ff8ab8681172abb1ca97ec761fc37101737ba0aa2e7c5">ERROR</enumvalue>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>RegisterRpcHandlers</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a2e9e2599f4d040549c868e31c78ffb98</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>ChangeState</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a2f583503ce64dee0ea2a646be04457b4</anchor>
      <arglist>(const State newState, const int delayMs=-1)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>DispatchMqttMessage</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>aed1fd7a5eb6a7db59ff65a543d9ad08c</anchor>
      <arglist>(const std::string &amp;topic, const std::string &amp;payload)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>DispatchRpcRequest</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a7e2ba2982f679b12ec4ddfc4a57c0250</anchor>
      <arglist>(const std::string &amp;topic, const std::string &amp;payload)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>DispatchAttributesRequest</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a3eb02be9103cd64dd5d78a79463396d4</anchor>
      <arglist>(const std::string &amp;payload)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>SendTelemtry</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a6ff5e8c190a97f6826fcd96455698c14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Result</type>
      <name>SendClientAttributes</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a0b7f26f537c88b72439a9ced40511b7b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>int</type>
      <name>ExtractRequestId</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a0b2dc6538b53b54f6c9cd1e9ea448d6a</anchor>
      <arglist>(const std::string &amp;url)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>NetworkController</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a8e5ccca6b167009c15df0dcd95b80ab1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~NetworkController</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a1993887bd751e0e999dc3961bdd4b103</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>NetworkController</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a66d45ae34c8d42be35d2c571a9874616</anchor>
      <arglist>(const NetworkController &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>NetworkController &amp;</type>
      <name>operator=</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a23d6b2b24c7269dafb3fdaba98e7ed67</anchor>
      <arglist>(const NetworkController &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Connectivity::WiFiCom *</type>
      <name>_wifiCom</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>af3552d68639e25d22be5b0b685c286ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Connectivity::MqttClient *</type>
      <name>_mqttClient</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a8a8af881d6d17b46711785f6a969700b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Connectivity::APPortal *</type>
      <name>_apPortal</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a410275e79ecab7f19fd8f3e10c2f94bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>State</type>
      <name>_state</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a031e77ee801767a745baa87bdf6641eb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Delay</type>
      <name>_telemetrySendDelay</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a60907cf988d44d7df21640753e454e4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Delay</type>
      <name>_delayTimeout</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>ad425f9ec593e9172921dc30668eded08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::map&lt; std::string, std::unique_ptr&lt; Handlers::IRpcHandler &gt; &gt;</type>
      <name>_rpcHandlers</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a28b719474ca2ba6e69e7d3472180bac4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>TELEMETRY_TOPIC</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a9f500b53b635e2b87f06f91c3fd6e9ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>RPC_REQUEST_TOPIC</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a92770df3acb92d6420e29d5f4e471c05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>RPC_RESPONSE_TOPIC</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a28363c40ca3fd12d4105adb4cd4ee74b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr const char *</type>
      <name>ATTRIBUTES_TOPIC</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a2fd7bdae2ff94545322c5139dd0c7d10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint32_t</type>
      <name>WIFI_CONNECTION_TIMEOUT_MS</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a107a319e6eebb6f6a9dfbbed232976be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint32_t</type>
      <name>TIME_SYNC_TIMEOUT_MS</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a77ed5a9f4a57c4081a369d1698c03e7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint32_t</type>
      <name>MQTT_CLIENT_TIMEOUT_MS</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a159933140604509ddacdfcb4d4ffcd15</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; NetworkController &gt;</name>
      <anchorfile>class_managers_1_1_network_controller.html</anchorfile>
      <anchor>a8bff844833d512be4e5b8f57304fdf04</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>OneWire</name>
    <filename>class_one_wire.html</filename>
    <member kind="function">
      <type></type>
      <name>OneWire</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>a9363813c295003567ee1f2b24a2b3dc9</anchor>
      <arglist>(PinName pin)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Reset</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>a5452bf040fdcfc3175e27c599153cc58</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>WriteBit</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>aa0f44c83ac22012ba155c8fe32ac2f84</anchor>
      <arglist>(int bit)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ReadBit</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>acda710e612874994a8bd35384a6ad8c3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>WriteByte</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>a8e9cd321116e44afc723626722367b7b</anchor>
      <arglist>(uint8_t data)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>ReadByte</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>aea78dbe466cffdec2faf2bbc7f448c98</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>DriveLow</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>aaa691a9ecef8f78b8215ab7e5450ff55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>Release</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>a5dfd82eafa995d7b22aca5c8276f7d41</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>portMUX_TYPE</type>
      <name>_mux</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>a50a741aac988a64b48a4ba010548564d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>gpio_num_t</type>
      <name>_pin</name>
      <anchorfile>class_one_wire.html</anchorfile>
      <anchor>abb6f60b55c5c69e9b62891e57e22f41a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Services::PowerController</name>
    <filename>class_services_1_1_power_controller.html</filename>
    <base>Base::Singleton&lt; PowerController &gt;</base>
    <base>Base::Service</base>
    <member kind="enumeration">
      <type></type>
      <name>Mode</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a79476486f2e4b82faa9b00987555eb03</anchor>
      <arglist></arglist>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="a79476486f2e4b82faa9b00987555eb03a211bc0d8ead7d875436571663f19bbaf">MODE_USB_POWERED</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="a79476486f2e4b82faa9b00987555eb03a21faa6f5f3dced214a09f2c36479e7fd">MODE_BATTERY_POWERED</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="a79476486f2e4b82faa9b00987555eb03aa9128640bf5e7e358083dbfb4b7e6ce3">_size</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>BatteryLevel</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>ac82adda78c03bab922a466b1abe602cc</anchor>
      <arglist></arglist>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602ccaa677dafe2e2a6113e9d4a58e533b97d8">LEVEL_FULL</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602cca9598fb0e2d2d0a518f6b061d3881462c">LEVEL_HIGH</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602cca3a11ed4bec0eb48b1f671fa485bee758">LEVEL_MEDIUM</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602cca94c228b5ab0165ef1f2cce1879351dcd">LEVEL_LOW</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602cca85c025beddcd2f9a89fddf3f35578ee3">LEVEL_CRITICAL</enumvalue>
      <enumvalue file="class_services_1_1_power_controller.html" anchor="ac82adda78c03bab922a466b1abe602ccaa9128640bf5e7e358083dbfb4b7e6ce3">_size</enumvalue>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetCurrentMode</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a07ae2171b362acc6f2129d45265c7513</anchor>
      <arglist>() -&gt; Mode</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>GetBatteryLevel</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a07579ff6fca9e94bd3bf82696cac277d</anchor>
      <arglist>() -&gt; BatteryLevel</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a50315cc671107123ae85fc0767cf8ac3</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a91ee77b7208248202bc7d38b006301e8</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>PowerController</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a22504d4d4dc5a5e72ac5c9fef7a0cb12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~PowerController</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>acec1b58fb9f99f3cae143029c96d2d63</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>PowerController</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>aa49218a5668ac3175c9625e1a54a84c0</anchor>
      <arglist>(const PowerController &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>PowerController &amp;</type>
      <name>operator=</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a60b2588d51b4d1d46b991f7ce7bd737e</anchor>
      <arglist>(const PowerController &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>AnalogIn</type>
      <name>_batteryVoltagePin</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a83ce2bcc8065c9d07bbc711f93153f84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>DigitalInOut</type>
      <name>_usbDetectPin</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a8008302c6d05fd9f2fe61cb02dc4987b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr float</type>
      <name>VOLTAGE_MULTIPLIER</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a45a4cc993583f50dd3b438c3aa8015b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; PowerController &gt;</name>
      <anchorfile>class_services_1_1_power_controller.html</anchorfile>
      <anchor>a0bf95b2d2879a77e9fba031fe2ef49c1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>PwmOut</name>
    <filename>class_pwm_out.html</filename>
    <member kind="function">
      <type></type>
      <name>PwmOut</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a5d154b8bdac08d3803fded855c1f9a8b</anchor>
      <arglist>(PinName pin, uint32_t freq=50, ledc_mode_t mode=LEDC_HIGH_SPEED_MODE, ledc_timer_bit_t resolution=LEDC_TIMER_10_BIT, ledc_channel_t channel=LEDC_CHANNEL_0, ledc_timer_t timer=LEDC_TIMER_0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetDuty</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>adfefc296506c37869d01aa36674e014c</anchor>
      <arglist>(float duty)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>FadeToDuty</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a515600faebe34c3c463318cd11602ea4</anchor>
      <arglist>(float duty, uint32_t time_ms)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Stop</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>ac6d935cfece187d4f55737722a487271</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>PinName</type>
      <name>_pin</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a69a3b33d87737f71e64fd195038125a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ledc_mode_t</type>
      <name>_mode</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>aff7c04b3732c561bf0cac922950e5993</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ledc_channel_t</type>
      <name>_channel</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a0a03a170724de6a5696d674b1e4bf637</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ledc_timer_t</type>
      <name>_timer</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a1702a3206707980495d5f358b2f02c08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint32_t</type>
      <name>_freq</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>ab272f0a518ca429018ea8fffc710e3a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ledc_timer_bit_t</type>
      <name>_resolution</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a4b914fc7fae9d5aac86a1c14b711cb7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>uint32_t</type>
      <name>_maxDuty</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>add0474018b94a693c682411a57ac0cc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_valid</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a9b678c7ca6345ca630744d3c65941688</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static bool</type>
      <name>_fade_service_installed</name>
      <anchorfile>class_pwm_out.html</anchorfile>
      <anchor>a68e51b599b70b13721ec479e433f9988</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Services::RealTimeClock</name>
    <filename>class_services_1_1_real_time_clock.html</filename>
    <base>Base::Singleton&lt; RealTimeClock &gt;</base>
    <base>Base::Service</base>
    <member kind="function">
      <type>auto</type>
      <name>GetTime</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>ab1585a566c7150af947ad630f1844857</anchor>
      <arglist>(Utils::DateTime &amp;time) -&gt; bool</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>SetTime</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>aa6068d9fb1865e980b19d96702da6388</anchor>
      <arglist>(const Utils::DateTime &amp;dateTime)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsTimeSynced</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a2d812e8f33b3771426c31ec88ebac405</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>InitTimeSync</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a2d171db360a38b296ee38a77e3d2e1a6</anchor>
      <arglist>(const char *timezone=nullptr) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>TimeSyncCallback</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a49bdf5f6798dcca31c43418d7ea27697</anchor>
      <arglist>(struct ::timeval *tv)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a84b0e45517d7d50da12f8e374b8e56a2</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a22ffd9c4750d0511457f42ba5ddb7a58</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>uint8_t</type>
      <name>DecToBcd</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a72441ce93b331cd67b3b9ff97e9ca081</anchor>
      <arglist>(uint8_t val)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>uint8_t</type>
      <name>BcdToDec</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a1c1a9d3023e6fede8f806b7ce410105e</anchor>
      <arglist>(uint8_t val)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>RealTimeClock</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>abe687d75d0b81b53ffe658c09da418ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~RealTimeClock</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a4b5dce78137f5a2f8fc6db2009661096</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>RealTimeClock</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>ac74d3ac9df9e9067311006cd3b5ed6b1</anchor>
      <arglist>(const RealTimeClock &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>RealTimeClock &amp;</type>
      <name>operator=</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a266aee964791ba9e570299611bcc8ead</anchor>
      <arglist>(const RealTimeClock &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>I2C</type>
      <name>_i2c</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a67b16550da25981e7d488618ef647423</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_isTimeSynced</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>ae93900e1d43cc6882227c25376150d44</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; RealTimeClock &gt;</name>
      <anchorfile>class_services_1_1_real_time_clock.html</anchorfile>
      <anchor>a3e84247c800d56b4b28a60a580e7aa13</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Result</name>
    <filename>struct_result.html</filename>
    <member kind="function" static="yes">
      <type>static Result</type>
      <name>Success</name>
      <anchorfile>struct_result.html</anchorfile>
      <anchor>a2c18b8e08c5fedbe7ba8eb0d9acd11c8</anchor>
      <arglist>(const std::optional&lt; std::string &gt; &amp;message=std::nullopt)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Result</type>
      <name>Error</name>
      <anchorfile>struct_result.html</anchorfile>
      <anchor>a5bd1dc0db453dcd6eb5eb0b8d97640af</anchor>
      <arglist>(const std::string &amp;message)</arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>success</name>
      <anchorfile>struct_result.html</anchorfile>
      <anchor>a849cf2825b5abc2411876ac92d41920d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::optional&lt; std::string &gt;</type>
      <name>responseMessage</name>
      <anchorfile>struct_result.html</anchorfile>
      <anchor>a7f43a4ee42b94d27b488ec922cfd72bb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Base::Service</name>
    <filename>class_base_1_1_service.html</filename>
    <base>Base::Module</base>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Service</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>af4f9c233d6d6d85350df35adab1d0d1b</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Update</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>a9c31099f5e4e6162fa980b6f10035975</anchor>
      <arglist>(int delayAfterMs=0)=delete</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Service</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>a38c34a862a60bd3651c0223fac3643db</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Service</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>a16e354f87d53baec0ff67298dbb74337</anchor>
      <arglist>(const Service &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Service &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>af6de23f248180d0eee5a5a8add07e17d</anchor>
      <arglist>(const Service &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Service</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>a89b28014a7b0ba2053cdb156e00a5f6c</anchor>
      <arglist>(Service &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Service &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_service.html</anchorfile>
      <anchor>a652742b34f569610bbd658f1b5896425</anchor>
      <arglist>(Service &amp;&amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Drivers::Servo</name>
    <filename>class_drivers_1_1_servo.html</filename>
    <base>Base::Singleton&lt; Servo &gt;</base>
    <base>Base::Driver</base>
    <member kind="function">
      <type>void</type>
      <name>SetAngle</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a53a6688cd1a8ded1b293a160768e9b65</anchor>
      <arglist>(float angle)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>FadeToAngle</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a4b4b52cbe88a8fbd0a4bac4a3495e110</anchor>
      <arglist>(float angle, uint32_t timeMs)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Release</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a4366ba79493a9bb940cda2fe5f1f63f0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>aaeadf3fffa45d9f146722311133b7e6f</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>afc8ac8e82280ff53052fdf9b4c0618d7</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a7117b2b01961395a014d99d167ef9cc8</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Servo</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>aa068ce7c328aa47179caf159f34918af</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~Servo</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a7bcaa18196222ff3f65b7cbcfde67a87</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Servo</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a35844abd9b05c910bca6da89b9e7af4e</anchor>
      <arglist>(const Servo &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>Servo &amp;</type>
      <name>operator=</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a91cd0b3d27463ecbb5442cfb2e80e7a0</anchor>
      <arglist>(const Servo &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>PwmOut</type>
      <name>_pwmOut</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a7e6ea9bdb851707736d46cdfb0443e5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr float</type>
      <name>PWM_FREQUENCY</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a7be5d41ac74b708483b001f203369989</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr float</type>
      <name>LOWER_DUTY</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a4fb8dd3c709925eee6cd4f8789947fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr float</type>
      <name>HIGHER_DUTY</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>aa07f4465a8a4e78c17e0406cbc9994e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr float</type>
      <name>MIN_SAFE_DUTY</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a1face9a7898cebba2fabcb29eca547b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr float</type>
      <name>MAX_SAFE_DUTY</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a4a7f0678cb144372b46f9a845db8c68d</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; Servo &gt;</name>
      <anchorfile>class_drivers_1_1_servo.html</anchorfile>
      <anchor>a9d3696a24abd84b072a9d753e87f0d34</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::SetTdsLimitsHandler</name>
    <filename>class_handlers_1_1_set_tds_limits_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_set_tds_limits_handler.html</anchorfile>
      <anchor>a52618992588ab9e6283bb65d3c769bab</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_set_tds_limits_handler.html</anchorfile>
      <anchor>af316ceef6789ceb8e9b4f14fd7645038</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::SetTempLimitsHandler</name>
    <filename>class_handlers_1_1_set_temp_limits_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_set_temp_limits_handler.html</anchorfile>
      <anchor>a841edb6e2e1729f1d3b74d4ff211a3c4</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_set_temp_limits_handler.html</anchorfile>
      <anchor>a41334323373977a982ed8bd203645ead</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::SetTimezoneHandler</name>
    <filename>class_handlers_1_1_set_timezone_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_set_timezone_handler.html</anchorfile>
      <anchor>a726d8eed231ac53a2febc1b4de1e913b</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_set_timezone_handler.html</anchorfile>
      <anchor>a5f176dafffbd5427e9a1979cfd26eb2e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Base::Singleton</name>
    <filename>class_base_1_1_singleton.html</filename>
    <templarg>typename T</templarg>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Singleton</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a35a306540d2449e0193b78de9c29bb87</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static T *</type>
      <name>GetInstance</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a4e5f0aaf965406eebd491dbb27452708</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Singleton</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a95b0ecccab2f3875f5b2f036ce49a0d5</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Singleton</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a07044c0471c1bdd624d221331e9b97ee</anchor>
      <arglist>(const Singleton &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a08f37a198cf2cef8d44461753db6f181</anchor>
      <arglist>(const Singleton &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>Singleton</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>ae72c7b7917237faf782df1948fd74018</anchor>
      <arglist>(Singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>Singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>class_base_1_1_singleton.html</anchorfile>
      <anchor>a532dbc4609fa59ae77fcd78531cf2e89</anchor>
      <arglist>(Singleton &amp;&amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SmartAquariumGuardian</name>
    <filename>class_smart_aquarium_guardian.html</filename>
    <base>Base::Singleton&lt; SmartAquariumGuardian &gt;</base>
    <base>Base::Manager</base>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a042f9fa1ee5ceec63e987da055bd0364</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a747ffb6382d36097e2e0dce2fa1cbb98</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a191ec77d8293c685d1fb75c86a2b2836</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>SmartAquariumGuardian</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>ae3209a41fce19069c609d77cb6d4d497</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~SmartAquariumGuardian</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a51700b70e324c1704f8c54690b5f32ff</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>SmartAquariumGuardian</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a8cf3b5fb8ef01a302874a4a2ebe661ff</anchor>
      <arglist>(const SmartAquariumGuardian &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>SmartAquariumGuardian &amp;</type>
      <name>operator=</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>ada7e2c7e37d44d2951334774fa229e1e</anchor>
      <arglist>(const SmartAquariumGuardian &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Delay</type>
      <name>_delay</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>a223777cab4525e72e3ae91199f6411a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; SmartAquariumGuardian &gt;</name>
      <anchorfile>class_smart_aquarium_guardian.html</anchorfile>
      <anchor>ab7b4c4f2b7f92492f28ed70189fbd75a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Services::StorageService</name>
    <filename>class_services_1_1_storage_service.html</filename>
    <base>Base::Singleton&lt; StorageService &gt;</base>
    <base>Base::Service</base>
    <member kind="function">
      <type>bool</type>
      <name>SaveFeedingScheduleInStorage</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a9b072212a576cf3f4504158f2b34d331</anchor>
      <arglist>(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>RemoveFeedingScheduleFromStorage</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>ae8a319103042451ae7fa1b3334628800</anchor>
      <arglist>(const int slotIndex)</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>SetDefaultConfig</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>aa2b6cd6bc18679969c70684622fc640a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Get</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>acdec3a759b1d8b3267353bd9582e4ef8</anchor>
      <arglist>(FieldId fieldId) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Set</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>ab8e18da5c87ae7b9c335fb922f567e7b</anchor>
      <arglist>(FieldId fieldId, T newValue)</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a6cbec7037cd8a919d755ba4fd572e3f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a463971e8323d85ee510a3c9567d23b14</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>aea1a92bad46e8241e6c25c045faade3e</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>SaveConfigInternal</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a4cfcda7e7bd6891e2409c7c3c78f8d76</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>bool</type>
      <name>LoadConfigInternal</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a4be9455c8751b4b94b852d2595ecfd54</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>StorageService</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a5db485c7edcf01e5b59f0a28135c5bf3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~StorageService</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a152ea0dccd6be10761834b4096dae88f</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>StorageService</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a97c9b2c2a3041ab990eadcd6b8749e38</anchor>
      <arglist>(const StorageService &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>StorageService &amp;</type>
      <name>operator=</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a417791d6f016141f55b1d2720f3b32bd</anchor>
      <arglist>(const StorageService &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Services::EepromMemory *</type>
      <name>_eepromMemory</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>aab8d56c59220d368a13cc6fa003804af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>MemoryConfigData</type>
      <name>_configCache</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a2e705efc18d5fa14b9abcc7bf3151c19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint16_t</type>
      <name>CONFIG_START_ADDR</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>ab8e6fb0829157549d6194f0116fc7d2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr size_t</type>
      <name>MAX_CONFIG_SIZE</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a7e5409c764c495e528d2ab14853fe623</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; StorageService &gt;</name>
      <anchorfile>class_services_1_1_storage_service.html</anchorfile>
      <anchor>a329a6b3c07a8c4b13cb7ed9dab9d5931</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Handlers::SyncDeviceHandler</name>
    <filename>class_handlers_1_1_sync_device_handler.html</filename>
    <base>Handlers::IRpcHandler</base>
    <member kind="function">
      <type>Result</type>
      <name>Handle</name>
      <anchorfile>class_handlers_1_1_sync_device_handler.html</anchorfile>
      <anchor>a8efce172e6058f384b45156beeaaa346</anchor>
      <arglist>(const std::string &amp;payload) override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>NAME</name>
      <anchorfile>class_handlers_1_1_sync_device_handler.html</anchorfile>
      <anchor>a23249fb3eb475cbb98ef5e2a7c6a8d64</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Drivers::TdsSensor</name>
    <filename>class_drivers_1_1_tds_sensor.html</filename>
    <base>Base::Singleton&lt; TdsSensor &gt;</base>
    <base>Base::Driver</base>
    <member kind="function">
      <type>int</type>
      <name>GetLastReading</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>af92116c76aa6faac5f61ca7791490eac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetTemperature</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a88e0655906f143a35c54f501a7c3d720</anchor>
      <arglist>(float temperature)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a0eabd5fc2e225acb7efe5174121650f2</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>ab3c029d6381d154a73f2a744fb39d82a</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a8ea563587a832ed71aafdaf7102fa7d2</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; float &gt;</type>
      <name>TdsReadingsVec</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a02b912085a36582eb325dcb3410115f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>float</type>
      <name>StoreAnalogReading</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>ad6a4e46880a406baa624fb930899edc3</anchor>
      <arglist>(const float reading)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>TdsSensor</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>ac71813eb23e2b59ac3f3504958574ef5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~TdsSensor</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>aeabd5fc9b150f2882a6482f586f49029</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>TdsSensor</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a60284b884d4f9648ac5e5e9a64c74f48</anchor>
      <arglist>(const TdsSensor &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>TdsSensor &amp;</type>
      <name>operator=</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>ab57650840cc5f433564dcee9f38e6aa1</anchor>
      <arglist>(const TdsSensor &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>AnalogIn</type>
      <name>_analogInPin</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>aeb5df0aac578537781f70bf803fedb05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TdsReadingsVec</type>
      <name>_analogReadingsVec</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a86434dc6f12df09bc42eaae8d988f468</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TdsReadingsVec::iterator</type>
      <name>_analogReadingsVecIter</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a502f71243513d4ee87becf71256c1ae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_temperature</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>aa25734642c93f8ea17e8cf35b7009740</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_lastReading</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a8966adbd4236f7d3c7138ffae52dc680</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>NUM_AVG_SAMPLES</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a247987c52447b5f62c3a5f8a514b7daf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>MIN_TDS_VALUE</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a68a7af64343ad3756655790095806db6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>MAX_TDS_VALUE</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a8a2c2bc2facab30f888cd83277248ac7</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; TdsSensor &gt;</name>
      <anchorfile>class_drivers_1_1_tds_sensor.html</anchorfile>
      <anchor>a3695387b171587268dd8bfc9637649f8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Comms::TelemetryPayload</name>
    <filename>class_comms_1_1_telemetry_payload.html</filename>
    <member kind="function">
      <type></type>
      <name>TelemetryPayload</name>
      <anchorfile>class_comms_1_1_telemetry_payload.html</anchorfile>
      <anchor>a8bf4033adc7b355f6456e1b2114ab5dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>ToJsonString</name>
      <anchorfile>class_comms_1_1_telemetry_payload.html</anchorfile>
      <anchor>a58fb6d679cb46154ebdca255043da48f</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_temperature</name>
      <anchorfile>class_comms_1_1_telemetry_payload.html</anchorfile>
      <anchor>afa3b38650ffb9b5e07c954f43fd63016</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_tds</name>
      <anchorfile>class_comms_1_1_telemetry_payload.html</anchorfile>
      <anchor>afc256463e00c2ce80ad9de9902a195fb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Drivers::TemperatureSensor</name>
    <filename>class_drivers_1_1_temperature_sensor.html</filename>
    <base>Base::Singleton&lt; TemperatureSensor &gt;</base>
    <base>Base::Driver</base>
    <member kind="function">
      <type>float</type>
      <name>GetLastReading</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>adb34278e65a22362052ded3e9b611264</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>ade456b53fceae0d0a989e79fce099502</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a4a6e0585691e348382b023281c97aec0</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>ad8487691127b9ba3cc190bcded81e4c3</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="typedef" protection="private">
      <type>std::vector&lt; float &gt;</type>
      <name>TempReadingsVec</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a319a1467d5c3ebf5398d0b57f6433c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="private">
      <type>int16_t</type>
      <name>GetRawReading</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>aff166a8910693a3a8fe3b78112879f6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type>float</type>
      <name>StoreReading</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>afcc8eca406e81aec2e0f23dfa5482459</anchor>
      <arglist>(float reading)</arglist>
    </member>
    <member kind="function" protection="private">
      <type>uint8_t</type>
      <name>CalculateCRC8</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a2d5d95a62eaf60337423a766f85f00f5</anchor>
      <arglist>(const uint8_t *addr, uint8_t len)</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>TemperatureSensor</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a2c358a87e10de530566a901fdd61fe84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~TemperatureSensor</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a32ef47df2a593caad5803e95387d9605</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>TemperatureSensor</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>aee671966c07bbacde22b46aaeb1a0dfb</anchor>
      <arglist>(const TemperatureSensor &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>TemperatureSensor &amp;</type>
      <name>operator=</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>ad209583e37d35e37e4868ee5f7fb0676</anchor>
      <arglist>(const TemperatureSensor &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>OneWire</type>
      <name>_oneWirePin</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>af443071bbc57ba30a706366dc3557913</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TempReadingsVec</type>
      <name>_rawReadingsVec</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a5773f23cf7a9a8aabea0cda7b5ec0e41</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>TempReadingsVec::iterator</type>
      <name>_rawReadingsVecIter</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>abf1463f4f555e894e52fd38efdf5187f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>_lastReading</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a8381bdff1718c2733dcabc3cff39743d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint8_t</type>
      <name>CMD_SKIP_ROM</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a25cbef3c5902743f9b39a69b19c5ad48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint8_t</type>
      <name>CMD_CONVERT_T</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a702bc3d8454ed13ca91b156cf17e1fef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr uint8_t</type>
      <name>CMD_READ_SCRATCH</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a89fc8e3294c08e8c4b9012b7484906fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>NUM_AVG_SAMPLES</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a16e0371d1b8646d16ab483c3eff4d044</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr float</type>
      <name>MIN_TEMP_VALUE</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a30302573fae8a63cd482cd0328d46755</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr float</type>
      <name>MAX_TEMP_VALUE</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>a9146161a40defbb1bc5b15d733fcb280</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; TemperatureSensor &gt;</name>
      <anchorfile>class_drivers_1_1_temperature_sensor.html</anchorfile>
      <anchor>aed7eeada6c80f2fa3d5b56543cab5394</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Drivers::GraphicDisplay::UIElement</name>
    <filename>class_drivers_1_1_graphic_display_1_1_u_i_element.html</filename>
    <member kind="function">
      <type></type>
      <name>UIElement</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a911add03c957ae32840596404acc48b0</anchor>
      <arglist>(lv_obj_t *lv_obj)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~UIElement</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>ad11e6307cea80c8748820a3a5a047e1d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetText</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a12b32066d0feb07b482c41b0967e8931</anchor>
      <arglist>(const char *newText)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Hide</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a145200f785959b5e80cca98f61a4223b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Show</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>aad349315a057b0e0afab5c632ca9d1c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetState1</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>ab3f75265aff5aa059e561c66459914f1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ClearState1</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>adde5b6a6ac8a904f5c56d9a128b62431</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsValid</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a166d581d5a5e63c5071ccf7b343c3a61</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>lv_obj_t *</type>
      <name>_lv_obj</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a4c11021aa79b6a862afac967ec068111</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>GraphicDisplay</name>
      <anchorfile>class_drivers_1_1_graphic_display_1_1_u_i_element.html</anchorfile>
      <anchor>a7e11de5f7b0f0f2d458519079b3432ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Managers::UserInterface</name>
    <filename>class_managers_1_1_user_interface.html</filename>
    <base>Base::Singleton&lt; UserInterface &gt;</base>
    <base>Base::Manager</base>
    <member kind="function">
      <type>void</type>
      <name>UpdateFeedingStatusIndicator</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a2ce14449b7c31cb75cfcbd48f690abfa</anchor>
      <arglist>(bool isFeeding)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a591b0260971eb0b659a7dc06208b5462</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a28ce130fa5651a865dd275a6f27e6ec9</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a796c6ebe3a8d964c52f70ed70d6c86f2</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnBatteryModeEnter</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a54ce8248b231b2ec4f5324d3f1edd686</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnBatteryModeExit</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a7ad602277552520cc690f39b3a97e5f8</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>UpdatePowerIndicator</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a53860a8f8d1fc1c382e5be4f35ac33e5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>UserInterface</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a48550fa03d7650ce14695da64348ef5e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~UserInterface</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a8d7d83297aa737a822f70630c6ed6471</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>UserInterface</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>acc5c00e48dea7b67154d3838b5d1269f</anchor>
      <arglist>(const UserInterface &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>UserInterface &amp;</type>
      <name>operator=</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ab3bb0615167dcb87dedfe630b6ddf8ad</anchor>
      <arglist>(const UserInterface &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>_firstUpdateDone</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>afc6218db62714a91c809832a78c17df9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay *</type>
      <name>_display</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>aa653c4ab0d646d1612f36f9e48c9cbe8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_batteryFullIcon</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a054abb08e3ea52bd3c5a5793f6aa15a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_batteryHighIcon</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a73d0138f6ef20fc3fa73d9a2de44d6d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_batteryMediumIcon</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ad3563bbac7e86f50753e26ea2a400ed9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_batteryLowIcon</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a1bb113d24882785ddbed3c4e0a03c53b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_batteryCriticalIcon</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>aa3a63c87dedad7f53a8fbb9806aa06b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tempValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a59399a4f81b62e2c283a5be43285ce41</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tempMinValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a5e4a99c7406f1ddf6416d5a7726f048a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tempMaxValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a3566067d40ac6932630900628a9eaf9c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tempPanel</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a477408afecbdd83696bab0abd255f982</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tdsValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>aa323cadca69bdeb9ec13081425f0a810</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tdsMinValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a6de66856b511ed6b8389821710ed7b2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tdsMaxValue</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a2ee4cba528d7eb8f336261b4015c763b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_tdsPanel</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ac6989ccbe861e1b9cd7312182740eda5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_wifiIconOn</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>adfe3d8bb4219e8a5ac7aaea116b8fdb9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_wifiIconOff</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a77a220cf396b8e980797abbba485bc2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_cloudIconOn</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>afe26203b8ec15dd0ef5a91f39307ef1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_cloudIconOff</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>aca63cc77cee344d28542bfcb3a64b6f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_apIconOn</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ad2cee37bb1b47e54fbc78cb1d990a1c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_time</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ad9014ef74832ff0d13dc2903742dad9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_feederPanel</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a90d666ce904af465516f96d43278f48c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_nextFeedingTime</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a215e2395c87c74377c86fa25ddc07d36</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_dosesPerDay</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a6b30a1dd567b644ed5fc5a409cbbdc3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::GraphicDisplay::UIElement *</type>
      <name>_dosesLeft</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ae1b27a165bc99231eeed8989d2f12ef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>DISPLAY_BRIGHTNESS_BATTERY_MODE</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a003c5936fb939ae329a190eb79dc078c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>DISPLAY_BRIGHTNESS_NORMAL_MODE</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>aa8493d85174a3f9a09f7ea07067cf4ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>DISPLAY_BRIGHTNESS_FIRST_UPDATE</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>ab9285b5d88cddab6a531dc9359e4d95f</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; UserInterface &gt;</name>
      <anchorfile>class_managers_1_1_user_interface.html</anchorfile>
      <anchor>a460bad3a8047798ac94f52bc27a8d9e8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Managers::WaterMonitor</name>
    <filename>class_managers_1_1_water_monitor.html</filename>
    <base>Base::Singleton&lt; WaterMonitor &gt;</base>
    <base>Base::Manager</base>
    <member kind="function">
      <type>int</type>
      <name>GetTdsReading</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>ac8a3c40bc1f6d09c01556603760180db</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>float</type>
      <name>GetTemperatureReading</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>ac04787d7d115c1d3542592afbd21801d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>SetTemperatureLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>abe40e8e62ffc667923aba0b093355737</anchor>
      <arglist>(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetTemperatureLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a2298ea3e8872004b89d1d1a6e0f3df7c</anchor>
      <arglist>(float &amp;minTemp, bool &amp;isMinLimitEnabled, float &amp;maxTemp, bool &amp;isMaxLimitEnabled) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsTemperatureOutOfLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a107599f17450d87591a0da1778179531</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Result</type>
      <name>SetTdsLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a11373a92e7c9c57bfce09dc9c41990a7</anchor>
      <arglist>(const int minTds, const bool isMinLimitEnabled, const int maxTds, const bool isMaxLimitEnabled)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>GetTdsLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a64f2474756981f71cdc4f716806be639</anchor>
      <arglist>(int &amp;minTds, bool &amp;isMinLimitEnabled, int &amp;maxTds, bool &amp;isMaxLimitEnabled) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsTdsOutOfLimits</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>afbc23e23ff646797c7de0c286866b991</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a96af797d0b909526ee17bb041e943fb8</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a04032f15715fc609c6bbdd41e3b607a3</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>af9915aed846b30ee3314470bcb6572ee</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>WaterMonitor</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a8b0ec2fc872bd16309a77ab5f10740ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~WaterMonitor</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a24e15bd00134a9a10029339787b80d4b</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>WaterMonitor</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>aaeb468a77171fe30920ce3c9c8932b12</anchor>
      <arglist>(const WaterMonitor &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>WaterMonitor &amp;</type>
      <name>operator=</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>ac8a3ed668ea24bbf9c71497482af45d4</anchor>
      <arglist>(const WaterMonitor &amp;)=delete</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::TemperatureSensor *</type>
      <name>_temperatureSensor</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a195d7d552b385b4c3343fbdebe7cd01a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Drivers::TdsSensor *</type>
      <name>_tdsSensor</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>aeba59a27f15f14b4e73223aab660c3bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr float</type>
      <name>MIN_TEMP_VALID_VALUE</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a21454d80572c80c1a6da75219e3da04f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr float</type>
      <name>MAX_TEMP_VALID_VALUE</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a35b7b5738d2cd2046bda0112effa19b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>MIN_TDS_VALID_VALUE</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>aac86f79618ebfa7171d93c41df8cb775</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private" static="yes">
      <type>static constexpr int</type>
      <name>MAX_TDS_VALID_VALUE</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a6b5544e851c3beb72ed936e458288b13</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; WaterMonitor &gt;</name>
      <anchorfile>class_managers_1_1_water_monitor.html</anchorfile>
      <anchor>a35086655160ab7c22e7634ac41578728</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Connectivity::WiFiCom</name>
    <filename>class_connectivity_1_1_wi_fi_com.html</filename>
    <base>Base::Singleton&lt; WiFiCom &gt;</base>
    <base>Base::Driver</base>
    <member kind="enumeration">
      <type></type>
      <name>State</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a1c4134f7433ff11212283de01103cfaf</anchor>
      <arglist></arglist>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafaa5daf7f2ebbba4975d61dab1c40188c7">IDLE</enumvalue>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafafaee4ca3c30ee18148ce3ada37466498">INIT</enumvalue>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafa9a14f95e151eec641316e7c784ce832d">CONNECTING</enumvalue>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafaa5afd6edd5336d91316964e493936858">CONNECTED</enumvalue>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafaad793e31fab5703fc5b990cf40f8a585">DISCONNECTING</enumvalue>
      <enumvalue file="class_connectivity_1_1_wi_fi_com.html" anchor="a1c4134f7433ff11212283de01103cfafabb1ca97ec761fc37101737ba0aa2e7c5">ERROR</enumvalue>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsConnected</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a60744661da8b6da7f8c9aef88f925cd4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>GetSsid</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a1779ccd4d569137f7bd025be8d7668b8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int8_t</type>
      <name>GetRssi</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a1a981fd884917803d438de83f5c59805</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Start</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a871b042b0c35cb2b4ce2a34bfc89b000</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Disconnect</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>ae86f7fd1ea4787966e098f3b43ebced6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetCredentials</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>aa49b6a129269aef182322d139f4fa610</anchor>
      <arglist>(const std::string &amp;ssid, const std::string &amp;password)</arglist>
    </member>
    <member kind="function">
      <type>State</type>
      <name>GetState</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>ad11886e2be1fef5a2eeb8004cf792e17</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const char *</type>
      <name>GetModuleName</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>acbaa269f184194dcc2446024204b5eaa</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>OnInit</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a3abf838dcb31631827f57c9187b7fd75</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>OnUpdate</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>ae990eeaa0ac3ebc015ce606091e51815</anchor>
      <arglist>() override</arglist>
    </member>
    <member kind="function" protection="private">
      <type>auto</type>
      <name>_Start</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a920ce46f50d8a3a3ade3413dc9e48bcc</anchor>
      <arglist>() -&gt; State</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>_Stop</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a1549ba003b0e00af418920b9dbf9f6d2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>WiFiCom</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a5e22e679003b35475cec702d57c83c90</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>~WiFiCom</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>aadaa0e78bc52191f6b009c168fcf16d9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="private">
      <type></type>
      <name>WiFiCom</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>aeee6c2f9d4a03a260927db77bae9f2ad</anchor>
      <arglist>(const WiFiCom &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private">
      <type>WiFiCom &amp;</type>
      <name>operator=</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a7f96a50dd104c49a5f1d85725f30f8f6</anchor>
      <arglist>(const WiFiCom &amp;)=delete</arglist>
    </member>
    <member kind="function" protection="private" static="yes">
      <type>static void</type>
      <name>EventHandler</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a9936fb1cfd2e67a3b6064cae730c0885</anchor>
      <arglist>(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>State</type>
      <name>_state</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a303c800341c9efa4da4849d7c1cfacda</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_ssid</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a2d3982074b754454f737a5bb84cbe312</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::string</type>
      <name>_password</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a7ed9333916ab1edc1b6e02c03da0d386</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::atomic&lt; bool &gt;</type>
      <name>_got_ip</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a79b49ce0767b43805e5ef2e3bf1c4dd6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::atomic&lt; bool &gt;</type>
      <name>_connected</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>af3f4da090dfd660f589df3e04e0726fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>esp_netif_t *</type>
      <name>_netif</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a08dec0b537e45241fbd7bf2f550c3a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>Base::Singleton&lt; WiFiCom &gt;</name>
      <anchorfile>class_connectivity_1_1_wi_fi_com.html</anchorfile>
      <anchor>a2a34733b695dbc6b5020b868696111b5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Base</name>
    <filename>namespace_base.html</filename>
    <class kind="class">Base::Driver</class>
    <class kind="class">Base::Manager</class>
    <class kind="class">Base::Module</class>
    <class kind="class">Base::Service</class>
    <class kind="class">Base::Singleton</class>
  </compound>
  <compound kind="namespace">
    <name>Comms</name>
    <filename>namespace_comms.html</filename>
    <class kind="class">Comms::TelemetryPayload</class>
    <class kind="class">Comms::ClientAttributesPayload</class>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>namespace_comms.html</anchorfile>
      <anchor>a53ea664b1a44cc85b91abeaeb1364c9c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Config</name>
    <filename>namespace_config.html</filename>
    <member kind="variable" static="yes">
      <type>static constexpr int</type>
      <name>SYSTEM_TIME_INCREMENT_MS</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>adf156f465a159bc7a04a5dc6cabc0fc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr int</type>
      <name>TELEMETRY_SEND_INTERVAL_MS</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>abb951566ae053caa7870184ed409aa9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>TDS_SENSOR_ADC_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a0620c777614465909c98fc40cf101d2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>TEMP_SENSOR_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>adedaa1d1590cc9ad64215c0bb05a1dc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>SERVO_FEEDER_PWM_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a914d79a1ee3f75edb59278de5b8db16b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_BACKLIGHT_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>abb83641b8df360bbb836000815d2e8a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_RESET_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>ace01159ee6cbd936d8225b790809d121</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_DC_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a557657d960cb09ab1ac37a4cddc1f727</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_CS_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a945b3747d19610fa5f0cebefb1dbfb74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_CLK_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>af564f7c223dda342fe503a191afb4a49</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_MOSI_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>af11bff418570b99d392cd1957d1f38fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_MISO_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a06d4136da0c5c2c1e2d38b5ab779589f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_TOUCH_CS_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a97de029378973e9dde329dbe49347df7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>DISP_TOUCH_IRQ_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a390e82a68caae5bde4c84a3917d918ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>I2C_SDA_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>aa853ef1b257541c45ddde9e2f5f128d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>I2C_SCL_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>ac24091e914db689cdeb246e8b39a58ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr uint8_t</type>
      <name>EEPROM_I2C_ADDRESS</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>adc21494d8567f03132a64c92b44b651f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr uint8_t</type>
      <name>RTC_I2C_ADDRESS</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>ab9fbacf079146673333750018ad2e908</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>BATTERY_ADC_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a97fc2db90fda7ef35932af664fee59af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>USB_DETECT_PIN</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>adbfbd7d25c577a9e67456560489ab642</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr PinName</type>
      <name>BUILTIN_LED</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a629da675df2f6c18ccfadafd1110630d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>MQTT_CLIENT_BROKER_URI</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a1e7d345a739bdb41a76d12033baa65f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const char *</type>
      <name>MQTT_CLIENT_USER_NAME</name>
      <anchorfile>namespace_config.html</anchorfile>
      <anchor>a907f4b61bcd042819cb82b4976e9cdfa</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Connectivity</name>
    <filename>namespace_connectivity.html</filename>
    <class kind="class">Connectivity::APPortal</class>
    <class kind="class">Connectivity::MqttClient</class>
    <class kind="class">Connectivity::WiFiCom</class>
  </compound>
  <compound kind="namespace">
    <name>Core</name>
    <filename>namespace_core.html</filename>
    <class kind="class">Core::GuardianProxy</class>
    <class kind="class">Core::IFoodFeeder</class>
    <class kind="class">Core::INetworkController</class>
    <class kind="class">Core::IPowerController</class>
    <class kind="class">Core::IRealTimeClock</class>
    <class kind="class">Core::IStorageService</class>
    <class kind="class">Core::IUserInterface</class>
    <class kind="class">Core::IWaterMonitor</class>
  </compound>
  <compound kind="namespace">
    <name>Drivers</name>
    <filename>namespace_drivers.html</filename>
    <class kind="class">Drivers::GraphicDisplay</class>
    <class kind="class">Drivers::Servo</class>
    <class kind="class">Drivers::TdsSensor</class>
    <class kind="class">Drivers::TemperatureSensor</class>
  </compound>
  <compound kind="namespace">
    <name>Handlers</name>
    <filename>namespace_handlers.html</filename>
    <class kind="class">Handlers::IRpcHandler</class>
    <class kind="class">Handlers::SetTempLimitsHandler</class>
    <class kind="class">Handlers::SetTdsLimitsHandler</class>
    <class kind="class">Handlers::AddFeedingScheduleHandler</class>
    <class kind="class">Handlers::DeleteFeedingScheduleHandler</class>
    <class kind="class">Handlers::FeedNowHandler</class>
    <class kind="class">Handlers::SetTimezoneHandler</class>
    <class kind="class">Handlers::FactoryResetHandler</class>
    <class kind="class">Handlers::SyncDeviceHandler</class>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>namespace_handlers.html</anchorfile>
      <anchor>acfa1081a5b87f753b67982791c8ff51e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Managers</name>
    <filename>namespace_managers.html</filename>
    <class kind="class">Managers::FoodFeeder</class>
    <class kind="class">Managers::NetworkController</class>
    <class kind="class">Managers::UserInterface</class>
    <class kind="class">Managers::WaterMonitor</class>
  </compound>
  <compound kind="namespace">
    <name>NetworkConfig</name>
    <filename>namespace_network_config.html</filename>
    <namespace>NetworkConfig::Key</namespace>
    <namespace>NetworkConfig::Value</namespace>
    <namespace>NetworkConfig::TelemetryKeys</namespace>
    <namespace>NetworkConfig::ClientAttributes</namespace>
  </compound>
  <compound kind="namespace">
    <name>NetworkConfig::ClientAttributes</name>
    <filename>namespace_network_config_1_1_client_attributes.html</filename>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TIMEZONE</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a5b054cbe0a10fe3c75b4a83988edfdf3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TEMP_LIMIT_MIN</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>ae313d1b2fe0f745763e6d167a07c3757</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TEMP_LIMIT_MIN_ENABLED</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a327383cb2db60903dc6c9bf2f26629ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TEMP_LIMIT_MAX</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a626e436789e81901c047f8aff9f4be68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TEMP_LIMIT_MAX_ENABLED</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a2967c1eb7408d4382be04e29c7f832d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TDS_LIMIT_MIN</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a93c34065e54dc756b5cd7c7fb7ba27f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TDS_LIMIT_MIN_ENABLED</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>ac447eac510f4e2a79c3514cde3b46363</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TDS_LIMIT_MAX</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a888354fc4541a2afd69dc99fbf3006ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TDS_LIMIT_MAX_ENABLED</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>ae759ab93545bcb83adc104fac36e9e93</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>FEEDING_SCHEDULE</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>ada38b42084bc07e9475d67801dd8dfc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>FEED_DOSE</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>ac7a884688904ca223d7e8ebcf0460792</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>FEED_TIME</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>aebbf931734a140a754d9d7588916abcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>FEED_SLOT_ID</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a09a41a07dcf6313109569e23af7693b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>FEED_ENABLED</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a92b24d9c54e4989c130fbca5faf70eab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>WIFI_SSID</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a04b0f9f32558f6dfe80b3a1b827805e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>WIFI_RSSI</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>af1e9fabfa40119469890cb7af80bea16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>DEVICE_TIME</name>
      <anchorfile>namespace_network_config_1_1_client_attributes.html</anchorfile>
      <anchor>a5822ac5a451bf4b8e69dd7f462863474</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>NetworkConfig::Key</name>
    <filename>namespace_network_config_1_1_key.html</filename>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>METHOD</name>
      <anchorfile>namespace_network_config_1_1_key.html</anchorfile>
      <anchor>a2d598dcf1da4d84ac9307a10401cb9ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>PARAMS</name>
      <anchorfile>namespace_network_config_1_1_key.html</anchorfile>
      <anchor>a4c80f00fb59b971bdb0d814bfc8d994b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>RESULT</name>
      <anchorfile>namespace_network_config_1_1_key.html</anchorfile>
      <anchor>a8e27d779f9ec52a3d86d6f5e115ff603</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>RESPONSE_MSG</name>
      <anchorfile>namespace_network_config_1_1_key.html</anchorfile>
      <anchor>a19b55346f7c95d3ae08bfb23a34770b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>RESPONSE_DATA</name>
      <anchorfile>namespace_network_config_1_1_key.html</anchorfile>
      <anchor>a1995525b8a3726db3e48af7f7c9040d9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>NetworkConfig::TelemetryKeys</name>
    <filename>namespace_network_config_1_1_telemetry_keys.html</filename>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TEMPERATURE</name>
      <anchorfile>namespace_network_config_1_1_telemetry_keys.html</anchorfile>
      <anchor>a37b34a52793ab6ccbf599e8604154e46</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>TDS</name>
      <anchorfile>namespace_network_config_1_1_telemetry_keys.html</anchorfile>
      <anchor>ac89a5154b6305f411a9924c7fb1ab923</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>NetworkConfig::Value</name>
    <filename>namespace_network_config_1_1_value.html</filename>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>RESULT_SUCCESS</name>
      <anchorfile>namespace_network_config_1_1_value.html</anchorfile>
      <anchor>a269453669fb9950d58f392207f335166</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>RESULT_ERROR</name>
      <anchorfile>namespace_network_config_1_1_value.html</anchorfile>
      <anchor>ab03c8da9fc1872891b7c4556d1c41b15</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Services</name>
    <filename>namespace_services.html</filename>
    <class kind="class">Services::EepromMemory</class>
    <class kind="struct">Services::FeedingScheduleEntry</class>
    <class kind="struct">Services::MemoryConfigData</class>
    <class kind="class">Services::PowerController</class>
    <class kind="class">Services::RealTimeClock</class>
    <class kind="class">Services::StorageService</class>
    <member kind="typedef">
      <type>std::vector&lt; FeedingScheduleEntry &gt;</type>
      <name>FeeddingScheduleList</name>
      <anchorfile>namespace_services.html</anchorfile>
      <anchor>a6c4cb54359da51d6372be0c5955fef61</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>FieldId</name>
      <anchorfile>namespace_services.html</anchorfile>
      <anchor>ab26ec5ce90ab1df99102fd622805f526</anchor>
      <arglist></arglist>
      <enumvalue file="namespace_services.html" anchor="ab26ec5ce90ab1df99102fd622805f526a4905ac9d6a22bdfc1ae096094ce6248d">COUNT</enumvalue>
    </member>
    <member kind="function">
      <type>void</type>
      <name>to_json</name>
      <anchorfile>namespace_services.html</anchorfile>
      <anchor>a366e66dc7d07e57c04033180a3d8b099</anchor>
      <arglist>(nlohmann::json &amp;j, const FeedingScheduleEntry &amp;e)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>from_json</name>
      <anchorfile>namespace_services.html</anchorfile>
      <anchor>a1c798bb6432428b3dd3c2b743e429896</anchor>
      <arglist>(const nlohmann::json &amp;j, FeedingScheduleEntry &amp;e)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Utils</name>
    <filename>namespace_utils.html</filename>
    <class kind="class">Utils::JsonPayloadParser</class>
    <class kind="class">Utils::DateTime</class>
    <member kind="typedef">
      <type>nlohmann::json</type>
      <name>Json</name>
      <anchorfile>namespace_utils.html</anchorfile>
      <anchor>a0642d0e6e4bfece76b25205eb61f31c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>base</name>
    <path>src/core/base/</path>
    <filename>dir_a74bb488207285314d55b30438bec1a4.html</filename>
    <file>driver.h</file>
    <file>manager.cpp</file>
    <file>manager.h</file>
    <file>module.h</file>
    <file>service.h</file>
    <file>singleton.h</file>
  </compound>
  <compound kind="dir">
    <name>comms</name>
    <path>src/managers/comms/</path>
    <filename>dir_f59455624e931dace3f7a031f307653c.html</filename>
    <file>cloud_payloads.h</file>
    <file>json_parser.h</file>
    <file>network_config.h</file>
    <file>rpc_handler.h</file>
  </compound>
  <compound kind="dir">
    <name>connectivity</name>
    <path>src/connectivity/</path>
    <filename>dir_a577b2e4acbf0750a76891912d9a4bb0.html</filename>
    <file>ap_portal.cpp</file>
    <file>ap_portal.h</file>
    <file>ap_portal_html.h</file>
    <file>mqtt_client.cpp</file>
    <file>mqtt_client.h</file>
    <file>wifi_com.cpp</file>
    <file>wifi_com.h</file>
  </compound>
  <compound kind="dir">
    <name>core</name>
    <path>src/core/</path>
    <filename>dir_aebb8dcc11953d78e620bbef0b9e2183.html</filename>
    <dir>base</dir>
    <file>guardian_proxy.cpp</file>
    <file>guardian_proxy.h</file>
    <file>guardian_public_interfaces.h</file>
    <file>smart_aquarium_guardian.cpp</file>
    <file>smart_aquarium_guardian.h</file>
  </compound>
  <compound kind="dir">
    <name>drivers</name>
    <path>framework/drivers/</path>
    <filename>dir_331e92d4b572cdb973ebdfc18b058078.html</filename>
    <file>analog_in.cpp</file>
    <file>analog_in.h</file>
    <file>digital_in_out.cpp</file>
    <file>digital_in_out.h</file>
    <file>i2c.cpp</file>
    <file>i2c.h</file>
    <file>one_wire.cpp</file>
    <file>one_wire.h</file>
    <file>pwm_out.cpp</file>
    <file>pwm_out.h</file>
  </compound>
  <compound kind="dir">
    <name>drivers</name>
    <path>src/drivers/</path>
    <filename>dir_c718a368270b13c54d94892d20736f45.html</filename>
    <file>graphic_display.cpp</file>
    <file>graphic_display.h</file>
    <file>servo.cpp</file>
    <file>servo.h</file>
    <file>tds_sensor.cpp</file>
    <file>tds_sensor.h</file>
    <file>temperature_sensor.cpp</file>
    <file>temperature_sensor.h</file>
  </compound>
  <compound kind="dir">
    <name>framework</name>
    <path>framework/</path>
    <filename>dir_644e041c3a6521da7b27eba0e4eb2b95.html</filename>
    <dir>drivers</dir>
    <dir>os</dir>
    <dir>util</dir>
    <file>common_defs.h</file>
    <file>debug_defs.h</file>
    <file>pin_names.h</file>
  </compound>
  <compound kind="dir">
    <name>include</name>
    <path>include/</path>
    <filename>dir_d44c64559bbebec7f509842c48db8b23.html</filename>
    <file>config.h</file>
  </compound>
  <compound kind="dir">
    <name>managers</name>
    <path>src/managers/</path>
    <filename>dir_da1d252641c1d690e9226c1cabf97c78.html</filename>
    <dir>comms</dir>
    <file>food_feeder.cpp</file>
    <file>food_feeder.h</file>
    <file>network_controller.cpp</file>
    <file>network_controller.h</file>
    <file>user_interface.cpp</file>
    <file>user_interface.h</file>
    <file>water_monitor.cpp</file>
    <file>water_monitor.h</file>
  </compound>
  <compound kind="dir">
    <name>memory</name>
    <path>src/services/memory/</path>
    <filename>dir_ba79337f69b80dc1b0f23d8e92302822.html</filename>
    <file>eeprom_memory.cpp</file>
    <file>eeprom_memory.h</file>
    <file>memory_config_data.h</file>
  </compound>
  <compound kind="dir">
    <name>os</name>
    <path>framework/os/</path>
    <filename>dir_42444ae66d3575ab4d6fac1e399c8223.html</filename>
    <file>async_worker.cpp</file>
    <file>async_worker.h</file>
  </compound>
  <compound kind="dir">
    <name>services</name>
    <path>src/services/</path>
    <filename>dir_1826a32a9d780ddbaf96ec88be56c4cd.html</filename>
    <dir>memory</dir>
    <file>power_controller.cpp</file>
    <file>power_controller.h</file>
    <file>real_time_clock.cpp</file>
    <file>real_time_clock.h</file>
    <file>storage_service.cpp</file>
    <file>storage_service.h</file>
  </compound>
  <compound kind="dir">
    <name>src</name>
    <path>src/</path>
    <filename>dir_68267d1309a1af8e8297ef4c3efbcdba.html</filename>
    <dir>connectivity</dir>
    <dir>core</dir>
    <dir>drivers</dir>
    <dir>managers</dir>
    <dir>services</dir>
    <dir>utils</dir>
    <file>main.cpp</file>
  </compound>
  <compound kind="dir">
    <name>util</name>
    <path>framework/util/</path>
    <filename>dir_c166c6dfd8b20648612635959740152d.html</filename>
    <file>delay.cpp</file>
    <file>delay.h</file>
  </compound>
  <compound kind="dir">
    <name>utils</name>
    <path>src/utils/</path>
    <filename>dir_313caf1132e152dd9b58bea13a4052ca.html</filename>
    <file>date_time.cpp</file>
    <file>date_time.h</file>
  </compound>
</tagfile>
