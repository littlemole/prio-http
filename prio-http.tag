<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>arg.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>arg_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <class kind="class">prio::Args</class>
  </compound>
  <compound kind="file">
    <name>attr.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>attr_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <class kind="class">prio::Attributes</class>
  </compound>
  <compound kind="file">
    <name>common.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>common_8h.html</filename>
    <class kind="class">prio::Http2SslCtx</class>
  </compound>
  <compound kind="file">
    <name>cookie.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>cookie_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <class kind="class">prio::Cookie</class>
    <class kind="class">prio::Cookies</class>
  </compound>
  <compound kind="file">
    <name>header.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>header_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <includes id="cookie_8h" name="cookie.h" local="yes" imported="no">priohttp/cookie.h</includes>
    <class kind="class">prio::HeaderValue</class>
    <class kind="class">prio::HeaderValues</class>
    <class kind="class">prio::Headers</class>
  </compound>
  <compound kind="file">
    <name>path.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>path_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <includes id="arg_8h" name="arg.h" local="yes" imported="no">priohttp/arg.h</includes>
    <includes id="queryparams_8h" name="queryparams.h" local="yes" imported="no">priohttp/queryparams.h</includes>
    <class kind="class">prio::PathInfo</class>
  </compound>
  <compound kind="file">
    <name>queryparams.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>queryparams_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <class kind="class">prio::QueryParams</class>
  </compound>
  <compound kind="file">
    <name>request.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>request_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <includes id="arg_8h" name="arg.h" local="yes" imported="no">priohttp/arg.h</includes>
    <includes id="path_8h" name="path.h" local="yes" imported="no">priohttp/path.h</includes>
    <includes id="header_8h" name="header.h" local="yes" imported="no">priohttp/header.h</includes>
    <includes id="attr_8h" name="attr.h" local="yes" imported="no">priohttp/attr.h</includes>
    <includes id="queryparams_8h" name="queryparams.h" local="yes" imported="no">priohttp/queryparams.h</includes>
    <class kind="class">prio::Request</class>
  </compound>
  <compound kind="file">
    <name>response.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>response_8h.html</filename>
    <includes id="request_8h" name="request.h" local="yes" imported="no">priohttp/request.h</includes>
    <includes id="header_8h" name="header.h" local="yes" imported="no">priohttp/header.h</includes>
    <class kind="class">prio::Response</class>
  </compound>
  <compound kind="file">
    <name>urlencode.h</name>
    <path>/home/mike/workspace/prio-http/include/priohttp/</path>
    <filename>urlencode_8h.html</filename>
    <includes id="common_8h" name="common.h" local="yes" imported="no">priohttp/common.h</includes>
    <class kind="class">prio::Urlencode</class>
  </compound>
  <compound kind="class">
    <name>prio::Args</name>
    <filename>classprio_1_1Args.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>exists</name>
      <anchorfile>classprio_1_1Args.html</anchorfile>
      <anchor>a9d421727429383881dd1c1ed06152b2b</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>get</name>
      <anchorfile>classprio_1_1Args.html</anchorfile>
      <anchor>adc6935c269f67a96c7d4882650b2eebb</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>keys</name>
      <anchorfile>classprio_1_1Args.html</anchorfile>
      <anchor>a2f3e0449f195431d94fea7e93aeef3eb</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Attributes</name>
    <filename>classprio_1_1Attributes.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>exists</name>
      <anchorfile>classprio_1_1Attributes.html</anchorfile>
      <anchor>a3bdf3c94fb57284e7ad7ff288e03095f</anchor>
      <arglist>(const std::string &amp;key) const noexcept</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>attr</name>
      <anchorfile>classprio_1_1Attributes.html</anchorfile>
      <anchor>a0230b0ef4df448461b4e229c28ed0445</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classprio_1_1Attributes.html</anchorfile>
      <anchor>aeb2a184d02741846086b178949428f3a</anchor>
      <arglist>(const std::string &amp;key, const std::any &amp;a)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classprio_1_1Attributes.html</anchorfile>
      <anchor>a169e43a02523e806f540d02b15d09e3e</anchor>
      <arglist>(const std::string &amp;key, T a)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classprio_1_1Attributes.html</anchorfile>
      <anchor>a094001f4a7b29b4af2f3f9dca50aaa37</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Cookie</name>
    <filename>classprio_1_1Cookie.html</filename>
    <member kind="function">
      <type></type>
      <name>Cookie</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>ab41331b28be0ac4a67dd8ecd5b36b8a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Cookie</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>adac89cc1dbef86f86e671eac93d11396</anchor>
      <arglist>(const std::string &amp;name, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>name</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a1a880a2c01b95b462884bef17c02d624</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>value</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a6c9f537b843d8a501ace85b1e1dd5e31</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>expires</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>acddf8d7d39b6295a746c576569502fc1</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>maxAge</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a2259ce0cde854a22c063e946689eb54f</anchor>
      <arglist>(int seconds)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>domain</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>ae74022b799613009f552575b910af9df</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>path</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>aa9d8df2ac366110e863081537bbcf825</anchor>
      <arglist>(const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>Cookie &amp;</type>
      <name>secure</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>acb476e34c3408cc833af25529a086d55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>name</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a26e21af4cf152306318f539b2a15bfb5</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>value</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>aea6653ebcd5696d4f29563178267f2bc</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>expires</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>ad7c764bd12eced860e01f5d9f8eae57d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>maxAge</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>ac0c028c5f4ac4a7af76f2d094a27792a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>domain</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a378b385f68c81480021b887f2f5a65c0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>path</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>aef1aca5327c147cab96b5f2ce4714651</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isSecure</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a9dc91cdb9a1363a3ac91f43d18043a92</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>str</name>
      <anchorfile>classprio_1_1Cookie.html</anchorfile>
      <anchor>a5e4759369b1e900c7479185854c51e7b</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Cookies</name>
    <filename>classprio_1_1Cookies.html</filename>
    <member kind="function">
      <type>Cookie</type>
      <name>parseCookie</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>aaf6f5763105a9ec186b6d316de949f93</anchor>
      <arglist>(const std::string &amp;txt)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Cookie &gt; &amp;</type>
      <name>parse</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a88c31504c05ffb908b69889f856b8f74</anchor>
      <arglist>(const std::string &amp;txt)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>exists</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a2220337b50cb4a377a5f8aea9bc0ef78</anchor>
      <arglist>(const std::string &amp;name) const</arglist>
    </member>
    <member kind="function">
      <type>const Cookie &amp;</type>
      <name>get</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a2dcb74cf763227a7b66c698f083a4570</anchor>
      <arglist>(const std::string &amp;name) const</arglist>
    </member>
    <member kind="function">
      <type>const std::vector&lt; Cookie &gt; &amp;</type>
      <name>all</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a0f98d15b15df238da113fecde985539c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Cookies &amp;</type>
      <name>add</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>af38ee9dbe177b7c7eba32ff8c454ea0b</anchor>
      <arglist>(const Cookie &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>empty</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a042279da45214dba11a20fe89b3d9653</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a7fe64e769cc95dea519e36583248ebc2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>classprio_1_1Cookies.html</anchorfile>
      <anchor>a0486bc7097e102ddccae8d9b2b3e043f</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Headers</name>
    <filename>classprio_1_1Headers.html</filename>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a422eba2d05e8f8e15146998bd37b3ccd</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>exists</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>ae5d2a1c877f7c53a9273901efccf4825</anchor>
      <arglist>(const std::string &amp;key) const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>get</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a11cb00d7dc429844e9daac10b8836d10</anchor>
      <arglist>(const std::string &amp;key) const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>accept</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a33295b344f300265f515b1f82fa3f71a</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>content_type</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>adb231282af680b09925245963a26996e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>content_length</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a553ccf2cb10fc7049473c0a46c15dbaa</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const Cookies &amp;</type>
      <name>cookies</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a0fda09fd06467211c53c9e6c98c257ce</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>Headers &amp;</type>
      <name>cookie</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>ab56e51233ee3f82b9004135baebb2b13</anchor>
      <arglist>(const Cookie &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>Headers &amp;</type>
      <name>set</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>a95ceb6a9e825729d1a034bd84b6d91a7</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>aa9435ee14b7aca63b4d0b5a474bd6e9d</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>HeaderValues</type>
      <name>values</name>
      <anchorfile>classprio_1_1Headers.html</anchorfile>
      <anchor>ae7e52b35d4f2a8d2bef7b934b4b541db</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::HeaderValue</name>
    <filename>classprio_1_1HeaderValue.html</filename>
    <member kind="function">
      <type>std::string</type>
      <name>main</name>
      <anchorfile>classprio_1_1HeaderValue.html</anchorfile>
      <anchor>a0367f086043d73894e9ac5af3477641a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::map&lt; std::string, std::string &gt;</type>
      <name>params</name>
      <anchorfile>classprio_1_1HeaderValue.html</anchorfile>
      <anchor>aecf758fbcb7b32194dab7091ed01c36a</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::HeaderValues</name>
    <filename>classprio_1_1HeaderValues.html</filename>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classprio_1_1HeaderValues.html</anchorfile>
      <anchor>a7019e49c639dcf13ba06ec2d09378064</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const HeaderValue &amp;</type>
      <name>operator[]</name>
      <anchorfile>classprio_1_1HeaderValues.html</anchorfile>
      <anchor>ab16f64d9269762a6f489b224f7b2d362</anchor>
      <arglist>(size_t index) const</arglist>
    </member>
    <member kind="function">
      <type>const HeaderValue &amp;</type>
      <name>value</name>
      <anchorfile>classprio_1_1HeaderValues.html</anchorfile>
      <anchor>a2d533a44af5c1ac04d994970acf7e89b</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Http2SslCtx</name>
    <filename>classprio_1_1Http2SslCtx.html</filename>
    <base>prio::SslCtx</base>
    <member kind="function">
      <type>void</type>
      <name>load_cert_pem</name>
      <anchorfile>classprio_1_1Http2SslCtx.html</anchorfile>
      <anchor>a57787ee2879d8df1d9b9fd65baf6bada</anchor>
      <arglist>(const std::string &amp;file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>enableHttp2</name>
      <anchorfile>classprio_1_1Http2SslCtx.html</anchorfile>
      <anchor>a072daa880fe36df7253d3d45c1d6f33e</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::PathInfo</name>
    <filename>classprio_1_1PathInfo.html</filename>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>action</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a419d62bbacce5bfe5f6bd2f24d2badc8</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>protocol</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a4860172a7ffb9f19d527251d57fd54f4</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>method</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>af853524ef6d2282edeeda8864a677bf3</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>url</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a63297f66c88563e867c69b093fb72d77</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>path</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>aa63ccd3feff1d263a6350dc04ee6613b</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>querystring</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a2cfa5c94a08d66cf83bf5dd6ee17ca8e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>QueryParams</type>
      <name>queryParams</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a01d21d9395d14c40035180f937b3b235</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>Args</type>
      <name>args</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a0096e7d2a6317f071294e24c3bfe1438</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classprio_1_1PathInfo.html</anchorfile>
      <anchor>a47cb374105a78aad96c05e0659a364f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::QueryParams</name>
    <filename>classprio_1_1QueryParams.html</filename>
    <member kind="function">
      <type></type>
      <name>QueryParams</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>ae7644856fef7369dd0adab2d3ea22308</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>QueryParams</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a4b243d9e4eb56c3fcc2f131cccee5f92</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>exists</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>ab4383afdd52b33fe692d416a3a647eb5</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>get</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a0b3ef2a2359d5f6fafcaa874053743bf</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>std::set&lt; std::string &gt;</type>
      <name>keys</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>aa5b06e0e3fd2d268a4775123432a3e51</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>array</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>addd005f829efbf13fd87cbaba3553a95</anchor>
      <arglist>(const std::string &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a2d209fb8887e2e8d3154a9b05687bef2</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a9bbc1c0d63d764a973fa1b0e7b8c68cc</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a4d339f4b69cc5ceb65ec6ae0c4190e8d</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string &amp;</type>
      <name>operator[]</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a99234a8e91e2599b7d77012f0dc4f57c</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classprio_1_1QueryParams.html</anchorfile>
      <anchor>a2a8887be7fdd4744fe89983b72b403ba</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Request</name>
    <filename>classprio_1_1Request.html</filename>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>body</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>abcc9d31f8101cb2e15ff173f4707ea65</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>ab4158a349d007907b70962779e3dd88d</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>aed026e4ed3cc64157df2d964dde5b099</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>operator[]</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>a3fcb764773b020190c26e17e43dd069b</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
    <member kind="variable">
      <type>PathInfo</type>
      <name>path</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>a6dbd67fc73a761da3c608301151dc878</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Headers</type>
      <name>headers</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>aa46faabc34f99ad49593d7a64ecaa9a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Attributes</type>
      <name>attributes</name>
      <anchorfile>classprio_1_1Request.html</anchorfile>
      <anchor>a7bcd2b37bf2d5e3d9e847e9e90512488</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Response</name>
    <filename>classprio_1_1Response.html</filename>
    <member kind="function">
      <type>Response &amp;</type>
      <name>contentType</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a4ee2010ecf5364cb3a8df23552fccae6</anchor>
      <arglist>(const std::string &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>header</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a22b22c73354f7b0c99cd5ad0f01bf6df</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>body</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a8e5b4cc26fc5aee7c9e222b102881eb4</anchor>
      <arglist>(const std::string &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>cookie</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a28658aa353145a416467d35b2cc69fa3</anchor>
      <arglist>(const Cookie &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>statusCode</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a912baf2ac259daf38573ff12f96243d4</anchor>
      <arglist>(int)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>status</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a2cd0b916aff49f8a5d9dc289121c17ac</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>ok</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>abfa7d81bcacb19b84871f956c081de4e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>error</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ada4f75ef1647934a5c53324af0fcc364</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>bad_request</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>aa42dd1c624f31c46559185ae913b2e66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>unauthorized</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ac3f246d7ffea434fa2c17d5d688196e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>forbidden</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a6f055771b88def9647f510294520800f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>not_found</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a440f519a695e40abc5e63024b851cfd0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>redirect</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ac1dd964ef4743478a8fe5b84e317ff64</anchor>
      <arglist>(const std::string &amp;s, int code=302)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>redirect</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>af3333b98f39eec288c53085c4bf8dc74</anchor>
      <arglist>(Request &amp;req, const std::string &amp;s, int code=302)</arglist>
    </member>
    <member kind="function">
      <type>Response &amp;</type>
      <name>gzip</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a321e273fe336ee8019442c26fed2e41a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>status</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ae776e2b663279f0bb0e0149e826c98ea</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>proto</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a4d161967cc603cb6dd8b44cf58c7607a</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>statusCode</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a89aa578344136fccf6831484a6c8d3e9</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>body</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ab78e3ae9f5c69d00652c6519b160133e</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a1d26cf0d85a562b544b8f7994efaf18d</anchor>
      <arglist>() const noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>toString</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a98eae4143e2ae3d719ba25857672e608</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>chunk</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a3f09563b6baaf10d3c9179a9203604e2</anchor>
      <arglist>(const std::string &amp;ch)</arglist>
    </member>
    <member kind="function">
      <type>repro::Future</type>
      <name>flush</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a74a7530ad5d85fa0bbfcb5273be6d708</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isChunked</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>aa5846ebf14f4514267e696709b72447f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isGzipped</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>af1aa772b62ce5b0ef49db36cb2bf5d69</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>Headers</type>
      <name>headers</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>ad0daa983329474eaec95ed90940dce05</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Attributes</type>
      <name>attributes</name>
      <anchorfile>classprio_1_1Response.html</anchorfile>
      <anchor>a6f21d18cfea13035a93444069a8039c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>prio::Urlencode</name>
    <filename>classprio_1_1Urlencode.html</filename>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>decode</name>
      <anchorfile>classprio_1_1Urlencode.html</anchorfile>
      <anchor>a8717d320d85f34ca1f5fd171bd5ccbda</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>decode</name>
      <anchorfile>classprio_1_1Urlencode.html</anchorfile>
      <anchor>a44e0a5596d0e8abdaab42a6f626f8599</anchor>
      <arglist>(const char *s, int len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>encode</name>
      <anchorfile>classprio_1_1Urlencode.html</anchorfile>
      <anchor>a90ab8ae0549cc5fcaeadc6240bd34a32</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::string</type>
      <name>encode</name>
      <anchorfile>classprio_1_1Urlencode.html</anchorfile>
      <anchor>aa27302106403aafd3866af013c6ec2f2</anchor>
      <arglist>(const char *s, int len)</arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>prio-http</title>
    <filename>index</filename>
  </compound>
</tagfile>
