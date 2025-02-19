using System;
using System.Collections.Generic;
using absLib.Types;
using CommunityToolkit.Mvvm.ComponentModel;

namespace CypCalib.Core.Shared
{
    # region 数据类型定义
    
    /**
     * @brief 对基本类型的封装，虽然现有的跟踪仪数据是 3 自由度，但是存在有 6 自由度测量的场景
     */
    public partial class Laser3Dof : ObservableObject
    {
        [ObservableProperty]
        private Point3D _data;
        
        public Laser3Dof()
        {
            _data = new Point3D(0, 0, 0);
        }
        
        public Laser3Dof(double x, double y, double z)
        {
            _data = new Point3D(x, y, z);
        }
    }
    
    /**
     * @brief 机械臂 Mcs 坐标与激光跟踪仪数据的组合
     */
    public partial class Robot6DLaserData : ObservableObject
    {
        [ObservableProperty]
        private Point6D _mcs;
        
        [ObservableProperty]
        private Laser3Dof _laser;

        public Robot6DLaserData()
        {
            _mcs = new Point6D();
            _laser = new Laser3Dof();
        }

        public Robot6DLaserData(Point6D mcs, Laser3Dof laser)
        {
            _mcs = mcs;
            _laser = laser;
        }
    }

    /**
     * @brief 机械臂模型基类
     */
    public abstract partial class RobotInfoBase : ObservableObject
    {
        private readonly int _axisCnt;

        [ObservableProperty]
        private double[] _a;

        [ObservableProperty]
        private double[] _d;
        
        [ObservableProperty]
        private double[] _origin;
        
        [ObservableProperty]
        private double[] _alpha;
        
        [ObservableProperty]
        private double[] _reduction;

        protected RobotInfoBase(int axisCnt)
        {
            if (axisCnt < 1)
            {
                throw new ArgumentException("axisCnt must be greater than 0.", nameof(axisCnt));
            }
            _axisCnt = axisCnt;
            _a = new double[_axisCnt];
            _d = new double[_axisCnt];
            _origin = new double[_axisCnt];
            _alpha = new double[_axisCnt];
            _reduction = new double[_axisCnt];
        }

        protected RobotInfoBase(int axisCnt, double[] a, double[] d, double[] origin, double[] alpha,
            double[] reduction) : this(axisCnt)
        {
            _axisCnt = axisCnt;
            
            // 验证长度
            ValidateArray(a, nameof(a));
            ValidateArray(d, nameof(d));
            ValidateArray(origin, nameof(origin));
            ValidateArray(alpha, nameof(alpha));
            ValidateArray(reduction, nameof(reduction));

            _a = a;
            _d = d;
            _origin = origin;
            _alpha = alpha;
            _reduction = reduction;
        }
        
        private void ValidateArray(double[] array, string paramName)
        {
            if (array.Length != _axisCnt)
            {
                throw new ArgumentException(
                    $"Array '{paramName}' length must match axis count {_axisCnt}", paramName
                );
            }
        }
    }
    
    /**
     * @brief 机械臂描述模型，包括 DH 模型、减速比、耦合比等
     */
    public partial class Robot6DInfo : RobotInfoBase
    {
        private const int INDUSTRIAL_ROBOT_AXIS_CNT = 6;
        
        [ObservableProperty]
        private double _j4J5Ratio;

        [ObservableProperty]
        private double _j4J6Ratio;

        [ObservableProperty]
        private double _j5J6Ratio;

        public Robot6DInfo() : base(INDUSTRIAL_ROBOT_AXIS_CNT) { }

        public Robot6DInfo(double[] a, double[] d, double[] origin, double[] alpha, double[] reduction,
            double j4J5Ratio, double j4J6Ratio, double j5J6Ratio) : base(INDUSTRIAL_ROBOT_AXIS_CNT, a, d, origin, alpha,
            reduction)
        {
            _j4J5Ratio = j4J5Ratio;
            _j4J6Ratio = j4J6Ratio;
            _j5J6Ratio = j5J6Ratio;
        }
    }

    /**
     * @brief 机械臂预标定配置
     */
    public partial class RobotPreCalibConfig : ObservableObject
    {
        private const int MAX_CALIB_PARAM_NUM = 33;
        
        // 生成随机构型的数量
        [ObservableProperty]
        private int _randomNum = 10000;
        
        // 参与标定的构型数量
        [ObservableProperty]
        private int _calibNum = 50;
        
        // 基坐标下 X 方向上最小移动距离
        [ObservableProperty]
        private double _minX = -1500;
        
        // X 方向上最大
        [ObservableProperty]
        private double _maxX = 1500;
        
        // Y 方向上最小
        [ObservableProperty]
        private double _minY = -1500;
        
        // Y 方向上最大
        [ObservableProperty]
        private double _maxY = 1500;
        
        // Z 方向上最小
        [ObservableProperty]
        private double _minZ = 300;
        
        // Z 方向上最大
        [ObservableProperty]
        private double _maxZ = 2500;
        
        // 最大入射角度
        [ObservableProperty]
        private double _maxAngle = 20;
        
        // 最优化目标
        [ObservableProperty]
        private int _optIdx = 1;
        
        // 关节限位
        [ObservableProperty]
        private double[] _negJointLim = new double[6];
        [ObservableProperty]
        private double[] _posJointLim = new double[6];
        
        // 被标定参数
        [ObservableProperty]
        private int[] _calibParamIdx = new int[MAX_CALIB_PARAM_NUM];
    }

    /**
     * @brief 机械臂主标定配置
     */
    public partial class RobotMainCalibConfig : ObservableObject
    {
        // 最终预标定分数
        [ObservableProperty]
        private int _primeMark = -1;
        
        // 工具坐标系
        [ObservableProperty]
        private double[] _toolCoords = new double[12];
        
        // 测量坐标系
        [ObservableProperty]
        private double[] _measCoords = new double[12];
        
        // 最优测量构型
        [ObservableProperty]
        private List<double> _primeConfig = new List<double>();
    }

    /**
     * @brief 机械臂结果配置
     */
    public partial class RobotCalibRstConfig : ObservableObject
    {
        // 标定结果
        [ObservableProperty]
        private Robot6DInfo _calibRstInfo = new Robot6DInfo();
        
        // 标定残差
        [ObservableProperty]
        private List<double> _residual = new List<double>();
        
        // 标定前、后误差
        [ObservableProperty]
        private Point3D _preError = new Point3D();
        [ObservableProperty]
        private Point3D _postError = new Point3D();
        
        // 是否已经保存（避免重复更新零点，导致标定失效）
        [ObservableProperty]
        private bool _hasSaved = false;
    }
    
    #endregion

    #region 信息类型定义

    /**
     * @brief 激光跟踪仪配置
     */
    public partial class LaserTrackerConfig : ObservableObject
    {
        [ObservableProperty]
        private string _ipAddress = "192.168.0.168";
        
        [ObservableProperty]
        private LaserTrackEnum _brand = LaserTrackEnum.lteAPI;
        
        [ObservableProperty]
        private int _smrSize = 0;
    }

    /**
     * @brief 测试环境类相关信息
     */
    public partial class EnvironmentInfo : ObservableObject
    {
        // 机器序列号
        [ObservableProperty]
        private string _machineId = "";
        
        // 操作者
        [ObservableProperty]
        private string _operator = "";
        
        // 环境温度
        [ObservableProperty]
        private double _temperature = 20;
        
        // 环境湿度
        [ObservableProperty]
        private double _humidity = 60;
    }

    #endregion
}
