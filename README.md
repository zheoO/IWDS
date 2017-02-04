==========================
 Iwds 君正智能手表互联服务SDK
==========================

注意事项：

1.使用Iwds需iOS8.0及以上版本；

2.在同时引入Iwds和高德地图(SDK)时，需手动删除文件夹Iwds.framework/Frameworks/，否者可能出现类名冲突问题。

配置Iwds：

1.手动配置

    从君正服务器同步JavaDocAndBuildOut工程，将/JavaDocAndBuildOut/iwds-api2-release/server/libs/ios/Iwds/Iwds.framework直接拷贝到Xcode工程中，并在Build Phases中将Iwds.framework添加为Embed Frameworks

2.自动配置

    通过CocoaPods配置Iwds，编写Podfile，文件内容如下：

        platform :ios, '8.0'
            pod 'IWDS_SDK', '~> 1.3.0'
        end

    然后在终端中跳转到Podfile所在目录执行以下命令：

        pod install

        pod update --no-repo-update

SDK使用方法：

    请参见君正手表开发平台提供的API指南：http://iwop.ingenic.com/zh-cn/develop/api-guide/api-guide-iwds-jar/
