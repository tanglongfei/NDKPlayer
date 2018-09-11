package com.pineteree.ndkplayer;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.SurfaceView;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    private TLFPlayer mPlayer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        SurfaceView surfaceView = findViewById(R.id.surfaceview);
        mPlayer = new TLFPlayer();
        mPlayer.setSurFaceView(surfaceView);
        mPlayer.setDataSource("rtmp://live.hkstv.hk.lxdns.com/live/hks");
        mPlayer.setOnPrepareListener(new TLFPlayer.OnPrepareListener() {
            @Override
            public void onPrepare() {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(MainActivity.this, "可以开始播放了", 0).show();
                    }
                });
            }
        });
    }


    public void start(View view) {
        mPlayer.prepare();
    }
}
