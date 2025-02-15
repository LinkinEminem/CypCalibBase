using System;
using System.Collections.Generic;
using absLib.Types;

namespace CypCalib.Core.Shared
{
    # region 数据类型定义
    
    /**
     * @brief 对基本类型的封装，虽然现有的跟踪仪数据是 3 自由度，但是存在有 6 自由度测量的场景
     */
    public class Laser3Dof
    {
        private Point3D Data { get; set; }

        public double X => Data.X;
        public double Y => Data.Y;
        public double Z => Data.Z;

        public Laser3Dof()
        {
            Data = new Point3D();
        }
        
        public Laser3Dof(double x, double y, double z)
        {
            Data = new Point3D(x, y, z);
        }
    }
    
    /**
     * @brief 机械臂 Mcs 坐标与激光跟踪仪数据的组合
     */
    public class Robot6DLaserData
    {
        public Point6D Mcs { get; set; }
        public Laser3Dof Laser { get; set; }

        public Robot6DLaserData()
        {
            Mcs = new Point6D();
            Laser = new Laser3Dof();
        }

        public Robot6DLaserData(Point6D mcs, Laser3Dof laser)
        {
            Mcs = mcs;
            Laser = laser;
        }
    }

    /**
     * @brief 机械臂模型基类
     */
    public abstract class RobotInfoBase
    {
        private readonly int _axisCnt;
        
        public double[] A { get; set; }
        public double[] D { get; set; }
        public double[] Origin { get; set; }
        public double[] Alpha { get; set; }
        public double[] Reduction { get; set; }

        protected RobotInfoBase(int axisCnt)
        {
            if (axisCnt < 1)
            {
                throw new ArgumentException("axisCnt must be greater than 0.", nameof(axisCnt));
            }
            _axisCnt = axisCnt;
            A = new double[_axisCnt];
            D = new double[_axisCnt];
            Origin = new double[_axisCnt];
            Alpha = new double[_axisCnt];
            Reduction = new double[_axisCnt];
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

            A = a;
            D = d;
            Origin = origin;
            Alpha = alpha;
            Reduction = reduction;
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
    public class Robot6DInfo : RobotInfoBase
    {
        private const int INDUSTRIAL_ROBOT_AXIS_CNT = 6;
        public double J4J5Ratio { get; set; } = 0;
        public double J4J6Ratio { get; set; } = 0;
        public double J5J6Ratio { get; set; } = 0;

        public Robot6DInfo() : base(INDUSTRIAL_ROBOT_AXIS_CNT) { }

        public Robot6DInfo(double[] a, double[] d, double[] origin, double[] alpha, double[] reduction,
            double j4J5Ratio, double j4J6Ratio, double j5J6Ratio) : base(INDUSTRIAL_ROBOT_AXIS_CNT, a, d, origin, alpha,
            reduction)
        {
            J4J5Ratio = j4J5Ratio;
            J4J6Ratio = j4J6Ratio;
            J5J6Ratio = j5J6Ratio;
        }
    }

    /**
     * @brief 机械臂预标定配置
     */
    public class RobotPreCalibConfig
    {
        private const int MAX_CALIB_PARAM_NUM = 33;
        
        // 生成随机构型的数量
        public int RandomNum { get; set; } = 8000;
        // 参与标定的构型数量
        public int CalibNum { get; set; } = 50;
        // 基坐标下 X 方向上最小移动距离
        public double MinX { get; set; } = -1500;
        // X 方向上最大
        public double MaxX { get; set; } = 1500;
        // Y 方向上最小
        public double MinY { get; set; } = -1500;
        // Y 方向上最大
        public double MaxY { get; set; } = 1500;
        // Z 方向上最小
        public double MinZ { get; set; } = 300;
        // Z 方向上最大
        public double MaxZ { get; set; } = 2500;
        // 最大入射角度
        public double MaxAngle { get; set; } = 20;
        // 最优化目标
        public int OptIdx { get; set; } = 0;
        // 关节限位
        public double[] NegJointLim { get; set; } = new double[6];
        public double[] PosJointLim { get; set; } = new double[6];
        // 被标定参数
        public int[] CalibParamIdx { get; set; } = new int[MAX_CALIB_PARAM_NUM];
    }

    /**
     * @brief 机械臂主标定配置
     */
    public class RobotMainCalibConfig
    {
        // 最终预标定分数
        public int PrimeMark { get; set; } = -1;
        // 工具坐标系
        public double[] ToolCoords { get; set; } = new double[12];
        // 测量坐标系
        public double[] MeasCoords { get; set; } = new double[12];
        // 最优测量构型
        public List<double> PrimeConfig { get; set; } = new List<double>();
    }

    /**
     * @brief 机械臂结果配置
     */
    public class RobotCalibRstConfig
    {
        // 标定结果
        public Robot6DInfo CalibRstInfo { get; } = new Robot6DInfo();
        // 标定残差
        public List<double> Residual { get; } = new List<double>();
        // 标定前、后误差
        public Point3D PreError { get; } = new Point3D();
        public Point3D PostError { get; } = new Point3D();
        // 是否已经保存（避免重复更新零点，导致标定失效）
        public bool HasSaved { get; set; } = false;
    }
    
    #endregion

    #region 信息类型定义

    /**
     * @brief 激光跟踪仪配置
     */
    public class LaserTrackerConfig
    {
        public string IPAddress { get; set; } = "192.168.0.168";
        public LaserTrackEnum Brand { get; set; } = LaserTrackEnum.lteAPI;
        public int SMRSize { get; set; } = 0;
    }

    /**
     * @brief 测试环境类相关信息
     */
    public class EnvironmentInfo
    {
        // 机器序列号
        public string MachineID { get; set; } = "";
        // 操作者
        public string Operator { get; set; } = "";
        // 环境温度
        public double Temperature { get; set; } = 0;
        // 环境湿度
        public double Humidity { get; set; } = 0;
    }

    #endregion
    
}
