# 文件名: my_launch_file.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # 定义要启动的第一个节点
    node1 = Node(
        package='ssr_pkg',      # 节点所在的功能包
        executable='chao_node',   # 节点的可执行文件名称
        name='chao_node'       # (可选) 给节点重命名
    )
    
    # 定义要启动的第二个节点
    node2 = Node(
        package='ssr_pkg',
        executable='yao_node',
    )
    
    # 定义要启动的第三个节点
    node3 = Node(
        package='act_pkg',
        executable='ma_node',
    )

    # 将所有节点添加到 LaunchDescription 中并返回
    return LaunchDescription([node1, node2, node3])