package com.pineteree.ndkplayer;

import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * 提供java 进行播放 停止等函数
 * Created by Administrator on 2018/9/7.
 */

public class TLFPlayer implements SurfaceHolder.Callback {

    static {
        System.loadLibrary("native-lib");
    }

    private SurfaceHolder mHolder;
    private String dataSource;


    /**
     * 让使用者 设置播放的文件 或者 直播地址
     *
     * @param dataSource
     */
    public void setDataSource(String dataSource) {
        this.dataSource = dataSource;
    }

    /**
     * 设置播放显示的画布
     *
     * @param surfaceView
     */
    public void setSurFaceView(SurfaceView surfaceView) {
        mHolder = surfaceView.getHolder();
        mHolder.addCallback(this);

    }


    public void onError(int errorCode) {
        System.out.println("Java接到回调:" + errorCode);
    }


    public void onPrepare() {
        if (null != listener) {
            listener.onPrepare();
        }
    }

    private OnPrepareListener listener;
    public void setOnPrepareListener(OnPrepareListener listener) {
        this.listener = listener;
    }

    public interface OnPrepareListener {
        void onPrepare();
    }

    /**
     * 准备好 要播放的视频
     */
    public void prepare() {
        native_prepare(dataSource);
    }

    /**
     * 开始播放
     */
    public void start() {

    }

    /**
     * 停止播放
     */
    public void stop() {

    }

    /**
     * 释放
     */
    public void release() {
        mHolder.removeCallback(this);
    }

    /**
     * 画布创建好了
     *
     * @param holder
     */
    @Override
    public void surfaceCreated(SurfaceHolder holder) {

    }

    /**
     * 画布发生了变化（横竖屏切换、按了home都会回调这个函数）
     *
     * @param holder
     * @param format
     * @param width
     * @param height
     */
    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    /**
     * 销毁画布 (按了home/退出应用/)
     *
     * @param holder
     */
    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    native void native_prepare(String dataSource);
}
