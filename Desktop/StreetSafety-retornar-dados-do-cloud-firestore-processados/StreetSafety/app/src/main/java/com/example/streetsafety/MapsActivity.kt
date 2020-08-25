package com.example.streetsafety

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuInflater
import android.view.MenuItem

import com.google.android.gms.maps.CameraUpdateFactory
import com.google.android.gms.maps.GoogleMap
import com.google.android.gms.maps.OnMapReadyCallback
import com.google.android.gms.maps.SupportMapFragment
import com.google.android.gms.maps.model.LatLng
import com.google.android.gms.maps.model.MarkerOptions
import com.google.firebase.firestore.FirebaseFirestore
import com.google.firebase.ktx.Firebase

class MapsActivity : AppCompatActivity(), OnMapReadyCallback {

    val db = FirebaseFirestore.getInstance()
    private lateinit var mapa: GoogleMap

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_maps)
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        val mapFragment = supportFragmentManager
            .findFragmentById(R.id.map) as SupportMapFragment
        mapFragment.getMapAsync(this)

        db.collection("maps").get().addOnSuccessListener { result ->

            for (document in result){
                val latitude: Double = document.getDouble("latitude" )!!
                val longitude: Double = document.getDouble("longitude")!!

                val latlog = LatLng(latitude,longitude)
                Log.d("longitude", "$latitude e $longitude")

                mapa.addMarker(
                    MarkerOptions()
                        .position(latlog))

            }
        }
    }

    // instancia o menu da barra de tarefas
    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        val inflater: MenuInflater = menuInflater
        inflater.inflate(R.menu.menu_recursos, menu)
        return true
    }

    // define o que implementar caso uma das opçoes da barra de tarefas seja clicada
    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle item selection
        return when (item.itemId) {
            R.id.nova_ocorrencia_opcao -> {
                adicionaOcorrencia()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    // inica outra acticity de ocorrencia
    private fun adicionaOcorrencia() {
        val intent = Intent(this, MainActivity::class.java)
        startActivity(intent)
    }


    // adiciona marcador com longo clique
    private fun setMapLongClick(map: GoogleMap) {
        map.setOnMapLongClickListener { latLng ->

            map.addMarker(
                MarkerOptions().position(latLng)
            )

            val coordenada = hashMapOf(
                "latitude" to latLng.latitude,
                "longitude" to latLng.longitude
            )
//            val coordenada = hashMapOf(
//                "latitude" to latLng.latitude.toString(),
//                "longitude" to latLng.longitude.toString()
//            )

            db.collection("maps").add(coordenada)
        }
    }


    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    override fun onMapReady(googleMap: GoogleMap) {
        mapa = googleMap

        // Add a marker in Sydney and move the camera
        val largoSaoSebastiao = LatLng(-3.130150,-60.022663)
        val zoom = 15f
        mapa.addMarker(MarkerOptions().position(largoSaoSebastiao).title("Marcado no largo"))
        mapa.moveCamera(CameraUpdateFactory.newLatLngZoom(largoSaoSebastiao, zoom))

        setMapLongClick(mapa)
    }
}