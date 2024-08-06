# 测例1

reconnect.c : 测试是否允许端口重用

1. 执行`./reconnect &`  创建socket服务端
2. 通过 `busybox telnet 127.0.0.1 12345` 连接服务端
3. 若已启用 `SO_REUSEADDR` 则再次连接成功，若未启用 `SO_REUSEADDR` 则连接失败

**说明**：同时测试 true 和 false 两种情况在 Starry 中显示比较混乱，因此手动设置打开或关闭 `SO_REUSEADDR`

# 测例2

multi_bind.c : 测试是否允许多个套接字绑定到同一个端口

1. 直接执行 `./multi_bind` 测试两个 socket 绑定到同一个端口

2. 若已启用 `SO_REUSEADDR` 则绑定成功，若未启用 `SO_REUSEADDR` 则绑定失败

**说明**：同测例1

