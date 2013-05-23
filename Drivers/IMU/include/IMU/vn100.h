  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>projectChimaera/Drivers/vNavIMU/include/vNavIMU/vn100.h at master · alexsleat/projectChimaera</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <link rel="logo" type="image/svg" href="http://github-media-downloads.s3.amazonaws.com/github-logo.svg" />
    <link rel="xhr-socket" href="/_sockets" />


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="github" name="octolytics-app-id" /><meta content="4387844" name="octolytics-actor-id" /><meta content="6724fef95ca66b1721a48fc3380a0f98824bd983c9188c66585a304e1c2c3abb" name="octolytics-actor-hash" />

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-fdebe8d3f60746fb87c763a59741ff520ae3d8e8.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-d530e63e2c132c7f0e6ac7228e7e1ab9ef2a8d94.css" media="all" rel="stylesheet" type="text/css" />
    


      <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-92d138f450f2960501e28397a2f63b0f100590f0.js" type="text/javascript"></script>
      <script src="https://a248.e.akamai.net/assets.github.com/assets/github-4037f12703c2d563310be4fcd52a229189468cce.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="80973bfd2a5cb09c53d745b26b5b1dc0">

        <link data-pjax-transient rel='permalink' href='/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/include/vNavIMU/vn100.h'>
    <meta property="og:title" content="projectChimaera"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/alexsleat/projectChimaera"/>
    <meta property="og:image" content="https://secure.gravatar.com/avatar/927d325c2b7f43176703521bcf18ea60?s=420&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid."/>
    <meta property="twitter:card" content="summary"/>
    <meta property="twitter:site" content="@GitHub">
    <meta property="twitter:title" content="alexsleat/projectChimaera"/>

    <meta name="description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid." />


    <meta content="305784" name="octolytics-dimension-user_id" /><meta content="2822251" name="octolytics-dimension-repository_id" />
  <link href="https://github.com/alexsleat/projectChimaera/commits/master.atom" rel="alternate" title="Recent Commits to projectChimaera:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-blob linux vis-public fork env-production  ">
    <div id="wrapper">

      

      
      
      

      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-icon mega-icon-invertocat"></span>
</a>

    <div class="divider-vertical"></div>

      <a href="/notifications" class="notification-indicator tooltipped downwards" title="You have no unread notifications">
    <span class="mail-status all-read"></span>
  </a>
  <div class="divider-vertical"></div>


      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">
  <a href="/search/advanced" class="advanced-search-icon tooltipped downwards command-bar-search" id="advanced_search" title="Advanced search"><span class="mini-icon mini-icon-advanced-search "></span></a>

  <input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    data-username="matthuxford"
      data-repo="alexsleat/projectChimaera"
      data-branch="master"
      data-sha="fb648041dc514e860e9140c35e4957488ffdfd31"
  >

    <input type="hidden" name="nwo" value="alexsleat/projectChimaera" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item selected">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="mini-icon help tooltipped downwards" title="Show command bar help">
    <span class="mini-icon mini-icon-help"></span>
  </span>

    <input type="hidden" name="type" value="Code" />

  <input type="hidden" name="ref" value="cmdform">

  <div class="divider-vertical"></div>

</form>
        <ul class="top-nav">
            <li class="explore"><a href="https://github.com/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="http://help.github.com">Help</a></li>
        </ul>
      </div>

    

  

    <ul id="user-links">
      <li>
        <a href="https://github.com/matthuxford" class="name">
          <img height="20" src="https://secure.gravatar.com/avatar/159652c8fcc2a050d13498a7c3af0bba?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png" width="20" /> matthuxford
        </a>
      </li>

        <li>
          <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a new repo">
            <span class="mini-icon mini-icon-create"></span>
          </a>
        </li>

        <li>
          <a href="/settings/profile" id="account_settings"
            class="tooltipped downwards"
            title="Account settings ">
            <span class="mini-icon mini-icon-account-settings"></span>
          </a>
        </li>
        <li>
          <a class="tooltipped downwards" href="/logout" data-method="post" id="logout" title="Sign out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
        </li>

    </ul>


<div class="js-new-dropdown-contents hidden">
  <ul class="dropdown-menu">
    <li>
      <a href="/new"><span class="mini-icon mini-icon-create"></span> New repository</a>
    </li>
    <li>
        <a href="https://github.com/alexsleat/projectChimaera/issues/new"><span class="mini-icon mini-icon-issue-opened"></span> New issue</a>
    </li>
    <li>
    </li>
    <li>
      <a href="/organizations/new"><span class="mini-icon mini-icon-u-list"></span> New organization</a>
    </li>
  </ul>
</div>


    
  </div>
</div>

      

      

      


            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="hentry">
        
        <div class="pagehead repohead instapaper_ignore readability-menu ">
          <div class="container">
            <div class="title-actions-bar">
              

<ul class="pagehead-actions">


    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="2822251" />

    <div class="select-menu js-menu-container js-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">
          <span class="mini-icon mini-icon-watching"></span>
          Watch
        </span>
      </span>

      <div class="select-menu-modal-holder js-menu-content">
        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container">

            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for discussions in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-watching"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

    <li class="js-toggler-container js-social-container starring-container ">
      <a href="/alexsleat/projectChimaera/unstar" class="minibutton js-toggler-target star-button starred upwards" title="Unstar this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-remove-star"></span>
        <span class="text">Unstar</span>
      </a>
      <a href="/alexsleat/projectChimaera/star" class="minibutton js-toggler-target star-button unstarred upwards" title="Star this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-star"></span>
        <span class="text">Star</span>
      </a>
      <a class="social-count js-social-count" href="/alexsleat/projectChimaera/stargazers">5</a>
    </li>

        <li>
          <a href="/alexsleat/projectChimaera/fork" class="minibutton js-toggler-target fork-button lighter upwards" title="Fork this repo" rel="nofollow" data-method="post">
            <span class="mini-icon mini-icon-branch-create"></span>
            <span class="text">Fork</span>
          </a>
          <a href="/alexsleat/projectChimaera/network" class="social-count">1</a>
        </li>


</ul>

              <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
                <span class="repo-label"><span>public</span></span>
                <span class="mega-icon mega-icon-repo-forked"></span>
                <span class="author vcard">
                  <a href="/alexsleat" class="url fn" itemprop="url" rel="author">
                  <span itemprop="title">alexsleat</span>
                  </a></span> /
                <strong><a href="/alexsleat/projectChimaera" class="js-current-repository">projectChimaera</a></strong>
                  <span class="fork-flag">
                    <span class="text">forked from <a href="/GarethG/ProjectRinzler">GarethG/ProjectRinzler</a></span>
                  </span>
              </h1>
            </div>

            
  <ul class="tabs">
    <li class="pulse-nav"><a href="/alexsleat/projectChimaera/pulse" class="js-selected-navigation-item " data-selected-links="pulse /alexsleat/projectChimaera/pulse" rel="nofollow"><span class="mini-icon mini-icon-pulse"></span></a></li>
    <li><a href="/alexsleat/projectChimaera" class="js-selected-navigation-item selected" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /alexsleat/projectChimaera">Code</a></li>
    <li><a href="/alexsleat/projectChimaera/network" class="js-selected-navigation-item " data-selected-links="repo_network /alexsleat/projectChimaera/network">Network</a></li>
    <li><a href="/alexsleat/projectChimaera/pulls" class="js-selected-navigation-item " data-selected-links="repo_pulls /alexsleat/projectChimaera/pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/alexsleat/projectChimaera/issues" class="js-selected-navigation-item " data-selected-links="repo_issues /alexsleat/projectChimaera/issues">Issues <span class='counter'>10</span></a></li>

      <li><a href="/alexsleat/projectChimaera/wiki" class="js-selected-navigation-item " data-selected-links="repo_wiki /alexsleat/projectChimaera/wiki">Wiki</a></li>


    <li><a href="/alexsleat/projectChimaera/graphs" class="js-selected-navigation-item " data-selected-links="repo_graphs repo_contributors /alexsleat/projectChimaera/graphs">Graphs</a></li>


  </ul>
  
<div class="tabnav">

  <span class="tabnav-right">
    <ul class="tabnav-tabs">
          <li><a href="/alexsleat/projectChimaera/tags" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_tags /alexsleat/projectChimaera/tags">Tags <span class="counter blank">0</span></a></li>
    </ul>
  </span>

  <div class="tabnav-widget scope">


    <div class="select-menu js-menu-container js-select-menu js-branch-menu">
      <a class="minibutton select-menu-button js-menu-target" data-hotkey="w" data-ref="master">
        <span class="mini-icon mini-icon-branch"></span>
        <i>branch:</i>
        <span class="js-select-button">master</span>
      </a>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">

        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Switch branches/tags</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-filters">
            <div class="select-menu-text-filter">
              <input type="text" id="commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
            </div>
            <div class="select-menu-tabs">
              <ul>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
                </li>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
                </li>
              </ul>
            </div><!-- /.select-menu-tabs -->
          </div><!-- /.select-menu-filters -->

          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="branches">

            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

                <div class="select-menu-item js-navigation-item selected">
                  <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
                  <a href="/alexsleat/projectChimaera/blob/master/Drivers/vNavIMU/include/vNavIMU/vn100.h" class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target" data-name="master" rel="nofollow" title="master">master</a>
                </div> <!-- /.select-menu-item -->
            </div>

              <div class="select-menu-no-results">Nothing to show</div>
          </div> <!-- /.select-menu-list -->


          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="tags">
            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

            </div>

            <div class="select-menu-no-results">Nothing to show</div>

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

  </div> <!-- /.scope -->

  <ul class="tabnav-tabs">
    <li><a href="/alexsleat/projectChimaera" class="selected js-selected-navigation-item tabnav-tab" data-selected-links="repo_source /alexsleat/projectChimaera">Files</a></li>
    <li><a href="/alexsleat/projectChimaera/commits/master" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_commits /alexsleat/projectChimaera/commits/master">Commits</a></li>
    <li><a href="/alexsleat/projectChimaera/branches" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_branches /alexsleat/projectChimaera/branches" rel="nofollow">Branches <span class="counter ">1</span></a></li>
  </ul>

</div>

  
  
  


            
          </div>
        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" class="container context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:acbb0760b0f4dddb17fb56ba30e2472d -->
<!-- blob contrib frag key: views10/v8/blob_contributors:v21:acbb0760b0f4dddb17fb56ba30e2472d -->


<div id="slider">
    <div class="frame-meta">

      <p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

        <div class="breadcrumb">
          <span class='bold'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">projectChimaera</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">Drivers</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">vNavIMU</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU/include" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">include</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU/include/vNavIMU" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">vNavIMU</span></a></span><span class="separator"> / </span><strong class="final-path">vn100.h</strong> <span class="js-zeroclipboard zeroclipboard-button" data-clipboard-text="Drivers/vNavIMU/include/vNavIMU/vn100.h" data-copied-hint="copied!" title="copy to clipboard"><span class="mini-icon mini-icon-clipboard"></span></span>
        </div>

      <a href="/alexsleat/projectChimaera/find/master" class="js-slide-to" data-hotkey="t" style="display:none">Show File Finder</a>


        <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/alexsleat/projectChimaera/contributors/master/Drivers/vNavIMU/include/vNavIMU/vn100.h">
          Fetching contributors…

          <div class="participation">
            <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif?1340659511" width="16" /></p>
            <p class="loader-error">Cannot retrieve contributors at this time</p>
          </div>
        </div>

    </div><!-- ./.frame-meta -->

    <div class="frames">
      <div class="frame" data-permalink-url="/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/include/vNavIMU/vn100.h" data-title="projectChimaera/Drivers/vNavIMU/include/vNavIMU/vn100.h at master · alexsleat/projectChimaera · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon mini-icon-text-file"></b></span>
                <span class="mode" title="File Mode">file</span>
                  <span>1251 lines (1144 sloc)</span>
                <span>65.211 kb</span>
              </div>
              <div class="actions">
                <div class="button-group">
                        <a class="minibutton tooltipped leftwards"
                           title="Clicking this button will automatically fork this project so you can edit the file"
                           href="/alexsleat/projectChimaera/edit/master/Drivers/vNavIMU/include/vNavIMU/vn100.h"
                           data-method="post" rel="nofollow">Edit</a>
                  <a href="/alexsleat/projectChimaera/raw/master/Drivers/vNavIMU/include/vNavIMU/vn100.h" class="button minibutton " id="raw-url">Raw</a>
                    <a href="/alexsleat/projectChimaera/blame/master/Drivers/vNavIMU/include/vNavIMU/vn100.h" class="button minibutton ">Blame</a>
                  <a href="/alexsleat/projectChimaera/commits/master/Drivers/vNavIMU/include/vNavIMU/vn100.h" class="button minibutton " rel="nofollow">History</a>
                </div><!-- /.button-group -->
              </div><!-- /.actions -->

            </div>
                <div class="blob-wrapper data type-c js-blob-data">
      <table class="file-code file-diff">
        <tr class="file-code-line">
          <td class="blob-line-nums">
            <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
<span id="L432" rel="#L432">432</span>
<span id="L433" rel="#L433">433</span>
<span id="L434" rel="#L434">434</span>
<span id="L435" rel="#L435">435</span>
<span id="L436" rel="#L436">436</span>
<span id="L437" rel="#L437">437</span>
<span id="L438" rel="#L438">438</span>
<span id="L439" rel="#L439">439</span>
<span id="L440" rel="#L440">440</span>
<span id="L441" rel="#L441">441</span>
<span id="L442" rel="#L442">442</span>
<span id="L443" rel="#L443">443</span>
<span id="L444" rel="#L444">444</span>
<span id="L445" rel="#L445">445</span>
<span id="L446" rel="#L446">446</span>
<span id="L447" rel="#L447">447</span>
<span id="L448" rel="#L448">448</span>
<span id="L449" rel="#L449">449</span>
<span id="L450" rel="#L450">450</span>
<span id="L451" rel="#L451">451</span>
<span id="L452" rel="#L452">452</span>
<span id="L453" rel="#L453">453</span>
<span id="L454" rel="#L454">454</span>
<span id="L455" rel="#L455">455</span>
<span id="L456" rel="#L456">456</span>
<span id="L457" rel="#L457">457</span>
<span id="L458" rel="#L458">458</span>
<span id="L459" rel="#L459">459</span>
<span id="L460" rel="#L460">460</span>
<span id="L461" rel="#L461">461</span>
<span id="L462" rel="#L462">462</span>
<span id="L463" rel="#L463">463</span>
<span id="L464" rel="#L464">464</span>
<span id="L465" rel="#L465">465</span>
<span id="L466" rel="#L466">466</span>
<span id="L467" rel="#L467">467</span>
<span id="L468" rel="#L468">468</span>
<span id="L469" rel="#L469">469</span>
<span id="L470" rel="#L470">470</span>
<span id="L471" rel="#L471">471</span>
<span id="L472" rel="#L472">472</span>
<span id="L473" rel="#L473">473</span>
<span id="L474" rel="#L474">474</span>
<span id="L475" rel="#L475">475</span>
<span id="L476" rel="#L476">476</span>
<span id="L477" rel="#L477">477</span>
<span id="L478" rel="#L478">478</span>
<span id="L479" rel="#L479">479</span>
<span id="L480" rel="#L480">480</span>
<span id="L481" rel="#L481">481</span>
<span id="L482" rel="#L482">482</span>
<span id="L483" rel="#L483">483</span>
<span id="L484" rel="#L484">484</span>
<span id="L485" rel="#L485">485</span>
<span id="L486" rel="#L486">486</span>
<span id="L487" rel="#L487">487</span>
<span id="L488" rel="#L488">488</span>
<span id="L489" rel="#L489">489</span>
<span id="L490" rel="#L490">490</span>
<span id="L491" rel="#L491">491</span>
<span id="L492" rel="#L492">492</span>
<span id="L493" rel="#L493">493</span>
<span id="L494" rel="#L494">494</span>
<span id="L495" rel="#L495">495</span>
<span id="L496" rel="#L496">496</span>
<span id="L497" rel="#L497">497</span>
<span id="L498" rel="#L498">498</span>
<span id="L499" rel="#L499">499</span>
<span id="L500" rel="#L500">500</span>
<span id="L501" rel="#L501">501</span>
<span id="L502" rel="#L502">502</span>
<span id="L503" rel="#L503">503</span>
<span id="L504" rel="#L504">504</span>
<span id="L505" rel="#L505">505</span>
<span id="L506" rel="#L506">506</span>
<span id="L507" rel="#L507">507</span>
<span id="L508" rel="#L508">508</span>
<span id="L509" rel="#L509">509</span>
<span id="L510" rel="#L510">510</span>
<span id="L511" rel="#L511">511</span>
<span id="L512" rel="#L512">512</span>
<span id="L513" rel="#L513">513</span>
<span id="L514" rel="#L514">514</span>
<span id="L515" rel="#L515">515</span>
<span id="L516" rel="#L516">516</span>
<span id="L517" rel="#L517">517</span>
<span id="L518" rel="#L518">518</span>
<span id="L519" rel="#L519">519</span>
<span id="L520" rel="#L520">520</span>
<span id="L521" rel="#L521">521</span>
<span id="L522" rel="#L522">522</span>
<span id="L523" rel="#L523">523</span>
<span id="L524" rel="#L524">524</span>
<span id="L525" rel="#L525">525</span>
<span id="L526" rel="#L526">526</span>
<span id="L527" rel="#L527">527</span>
<span id="L528" rel="#L528">528</span>
<span id="L529" rel="#L529">529</span>
<span id="L530" rel="#L530">530</span>
<span id="L531" rel="#L531">531</span>
<span id="L532" rel="#L532">532</span>
<span id="L533" rel="#L533">533</span>
<span id="L534" rel="#L534">534</span>
<span id="L535" rel="#L535">535</span>
<span id="L536" rel="#L536">536</span>
<span id="L537" rel="#L537">537</span>
<span id="L538" rel="#L538">538</span>
<span id="L539" rel="#L539">539</span>
<span id="L540" rel="#L540">540</span>
<span id="L541" rel="#L541">541</span>
<span id="L542" rel="#L542">542</span>
<span id="L543" rel="#L543">543</span>
<span id="L544" rel="#L544">544</span>
<span id="L545" rel="#L545">545</span>
<span id="L546" rel="#L546">546</span>
<span id="L547" rel="#L547">547</span>
<span id="L548" rel="#L548">548</span>
<span id="L549" rel="#L549">549</span>
<span id="L550" rel="#L550">550</span>
<span id="L551" rel="#L551">551</span>
<span id="L552" rel="#L552">552</span>
<span id="L553" rel="#L553">553</span>
<span id="L554" rel="#L554">554</span>
<span id="L555" rel="#L555">555</span>
<span id="L556" rel="#L556">556</span>
<span id="L557" rel="#L557">557</span>
<span id="L558" rel="#L558">558</span>
<span id="L559" rel="#L559">559</span>
<span id="L560" rel="#L560">560</span>
<span id="L561" rel="#L561">561</span>
<span id="L562" rel="#L562">562</span>
<span id="L563" rel="#L563">563</span>
<span id="L564" rel="#L564">564</span>
<span id="L565" rel="#L565">565</span>
<span id="L566" rel="#L566">566</span>
<span id="L567" rel="#L567">567</span>
<span id="L568" rel="#L568">568</span>
<span id="L569" rel="#L569">569</span>
<span id="L570" rel="#L570">570</span>
<span id="L571" rel="#L571">571</span>
<span id="L572" rel="#L572">572</span>
<span id="L573" rel="#L573">573</span>
<span id="L574" rel="#L574">574</span>
<span id="L575" rel="#L575">575</span>
<span id="L576" rel="#L576">576</span>
<span id="L577" rel="#L577">577</span>
<span id="L578" rel="#L578">578</span>
<span id="L579" rel="#L579">579</span>
<span id="L580" rel="#L580">580</span>
<span id="L581" rel="#L581">581</span>
<span id="L582" rel="#L582">582</span>
<span id="L583" rel="#L583">583</span>
<span id="L584" rel="#L584">584</span>
<span id="L585" rel="#L585">585</span>
<span id="L586" rel="#L586">586</span>
<span id="L587" rel="#L587">587</span>
<span id="L588" rel="#L588">588</span>
<span id="L589" rel="#L589">589</span>
<span id="L590" rel="#L590">590</span>
<span id="L591" rel="#L591">591</span>
<span id="L592" rel="#L592">592</span>
<span id="L593" rel="#L593">593</span>
<span id="L594" rel="#L594">594</span>
<span id="L595" rel="#L595">595</span>
<span id="L596" rel="#L596">596</span>
<span id="L597" rel="#L597">597</span>
<span id="L598" rel="#L598">598</span>
<span id="L599" rel="#L599">599</span>
<span id="L600" rel="#L600">600</span>
<span id="L601" rel="#L601">601</span>
<span id="L602" rel="#L602">602</span>
<span id="L603" rel="#L603">603</span>
<span id="L604" rel="#L604">604</span>
<span id="L605" rel="#L605">605</span>
<span id="L606" rel="#L606">606</span>
<span id="L607" rel="#L607">607</span>
<span id="L608" rel="#L608">608</span>
<span id="L609" rel="#L609">609</span>
<span id="L610" rel="#L610">610</span>
<span id="L611" rel="#L611">611</span>
<span id="L612" rel="#L612">612</span>
<span id="L613" rel="#L613">613</span>
<span id="L614" rel="#L614">614</span>
<span id="L615" rel="#L615">615</span>
<span id="L616" rel="#L616">616</span>
<span id="L617" rel="#L617">617</span>
<span id="L618" rel="#L618">618</span>
<span id="L619" rel="#L619">619</span>
<span id="L620" rel="#L620">620</span>
<span id="L621" rel="#L621">621</span>
<span id="L622" rel="#L622">622</span>
<span id="L623" rel="#L623">623</span>
<span id="L624" rel="#L624">624</span>
<span id="L625" rel="#L625">625</span>
<span id="L626" rel="#L626">626</span>
<span id="L627" rel="#L627">627</span>
<span id="L628" rel="#L628">628</span>
<span id="L629" rel="#L629">629</span>
<span id="L630" rel="#L630">630</span>
<span id="L631" rel="#L631">631</span>
<span id="L632" rel="#L632">632</span>
<span id="L633" rel="#L633">633</span>
<span id="L634" rel="#L634">634</span>
<span id="L635" rel="#L635">635</span>
<span id="L636" rel="#L636">636</span>
<span id="L637" rel="#L637">637</span>
<span id="L638" rel="#L638">638</span>
<span id="L639" rel="#L639">639</span>
<span id="L640" rel="#L640">640</span>
<span id="L641" rel="#L641">641</span>
<span id="L642" rel="#L642">642</span>
<span id="L643" rel="#L643">643</span>
<span id="L644" rel="#L644">644</span>
<span id="L645" rel="#L645">645</span>
<span id="L646" rel="#L646">646</span>
<span id="L647" rel="#L647">647</span>
<span id="L648" rel="#L648">648</span>
<span id="L649" rel="#L649">649</span>
<span id="L650" rel="#L650">650</span>
<span id="L651" rel="#L651">651</span>
<span id="L652" rel="#L652">652</span>
<span id="L653" rel="#L653">653</span>
<span id="L654" rel="#L654">654</span>
<span id="L655" rel="#L655">655</span>
<span id="L656" rel="#L656">656</span>
<span id="L657" rel="#L657">657</span>
<span id="L658" rel="#L658">658</span>
<span id="L659" rel="#L659">659</span>
<span id="L660" rel="#L660">660</span>
<span id="L661" rel="#L661">661</span>
<span id="L662" rel="#L662">662</span>
<span id="L663" rel="#L663">663</span>
<span id="L664" rel="#L664">664</span>
<span id="L665" rel="#L665">665</span>
<span id="L666" rel="#L666">666</span>
<span id="L667" rel="#L667">667</span>
<span id="L668" rel="#L668">668</span>
<span id="L669" rel="#L669">669</span>
<span id="L670" rel="#L670">670</span>
<span id="L671" rel="#L671">671</span>
<span id="L672" rel="#L672">672</span>
<span id="L673" rel="#L673">673</span>
<span id="L674" rel="#L674">674</span>
<span id="L675" rel="#L675">675</span>
<span id="L676" rel="#L676">676</span>
<span id="L677" rel="#L677">677</span>
<span id="L678" rel="#L678">678</span>
<span id="L679" rel="#L679">679</span>
<span id="L680" rel="#L680">680</span>
<span id="L681" rel="#L681">681</span>
<span id="L682" rel="#L682">682</span>
<span id="L683" rel="#L683">683</span>
<span id="L684" rel="#L684">684</span>
<span id="L685" rel="#L685">685</span>
<span id="L686" rel="#L686">686</span>
<span id="L687" rel="#L687">687</span>
<span id="L688" rel="#L688">688</span>
<span id="L689" rel="#L689">689</span>
<span id="L690" rel="#L690">690</span>
<span id="L691" rel="#L691">691</span>
<span id="L692" rel="#L692">692</span>
<span id="L693" rel="#L693">693</span>
<span id="L694" rel="#L694">694</span>
<span id="L695" rel="#L695">695</span>
<span id="L696" rel="#L696">696</span>
<span id="L697" rel="#L697">697</span>
<span id="L698" rel="#L698">698</span>
<span id="L699" rel="#L699">699</span>
<span id="L700" rel="#L700">700</span>
<span id="L701" rel="#L701">701</span>
<span id="L702" rel="#L702">702</span>
<span id="L703" rel="#L703">703</span>
<span id="L704" rel="#L704">704</span>
<span id="L705" rel="#L705">705</span>
<span id="L706" rel="#L706">706</span>
<span id="L707" rel="#L707">707</span>
<span id="L708" rel="#L708">708</span>
<span id="L709" rel="#L709">709</span>
<span id="L710" rel="#L710">710</span>
<span id="L711" rel="#L711">711</span>
<span id="L712" rel="#L712">712</span>
<span id="L713" rel="#L713">713</span>
<span id="L714" rel="#L714">714</span>
<span id="L715" rel="#L715">715</span>
<span id="L716" rel="#L716">716</span>
<span id="L717" rel="#L717">717</span>
<span id="L718" rel="#L718">718</span>
<span id="L719" rel="#L719">719</span>
<span id="L720" rel="#L720">720</span>
<span id="L721" rel="#L721">721</span>
<span id="L722" rel="#L722">722</span>
<span id="L723" rel="#L723">723</span>
<span id="L724" rel="#L724">724</span>
<span id="L725" rel="#L725">725</span>
<span id="L726" rel="#L726">726</span>
<span id="L727" rel="#L727">727</span>
<span id="L728" rel="#L728">728</span>
<span id="L729" rel="#L729">729</span>
<span id="L730" rel="#L730">730</span>
<span id="L731" rel="#L731">731</span>
<span id="L732" rel="#L732">732</span>
<span id="L733" rel="#L733">733</span>
<span id="L734" rel="#L734">734</span>
<span id="L735" rel="#L735">735</span>
<span id="L736" rel="#L736">736</span>
<span id="L737" rel="#L737">737</span>
<span id="L738" rel="#L738">738</span>
<span id="L739" rel="#L739">739</span>
<span id="L740" rel="#L740">740</span>
<span id="L741" rel="#L741">741</span>
<span id="L742" rel="#L742">742</span>
<span id="L743" rel="#L743">743</span>
<span id="L744" rel="#L744">744</span>
<span id="L745" rel="#L745">745</span>
<span id="L746" rel="#L746">746</span>
<span id="L747" rel="#L747">747</span>
<span id="L748" rel="#L748">748</span>
<span id="L749" rel="#L749">749</span>
<span id="L750" rel="#L750">750</span>
<span id="L751" rel="#L751">751</span>
<span id="L752" rel="#L752">752</span>
<span id="L753" rel="#L753">753</span>
<span id="L754" rel="#L754">754</span>
<span id="L755" rel="#L755">755</span>
<span id="L756" rel="#L756">756</span>
<span id="L757" rel="#L757">757</span>
<span id="L758" rel="#L758">758</span>
<span id="L759" rel="#L759">759</span>
<span id="L760" rel="#L760">760</span>
<span id="L761" rel="#L761">761</span>
<span id="L762" rel="#L762">762</span>
<span id="L763" rel="#L763">763</span>
<span id="L764" rel="#L764">764</span>
<span id="L765" rel="#L765">765</span>
<span id="L766" rel="#L766">766</span>
<span id="L767" rel="#L767">767</span>
<span id="L768" rel="#L768">768</span>
<span id="L769" rel="#L769">769</span>
<span id="L770" rel="#L770">770</span>
<span id="L771" rel="#L771">771</span>
<span id="L772" rel="#L772">772</span>
<span id="L773" rel="#L773">773</span>
<span id="L774" rel="#L774">774</span>
<span id="L775" rel="#L775">775</span>
<span id="L776" rel="#L776">776</span>
<span id="L777" rel="#L777">777</span>
<span id="L778" rel="#L778">778</span>
<span id="L779" rel="#L779">779</span>
<span id="L780" rel="#L780">780</span>
<span id="L781" rel="#L781">781</span>
<span id="L782" rel="#L782">782</span>
<span id="L783" rel="#L783">783</span>
<span id="L784" rel="#L784">784</span>
<span id="L785" rel="#L785">785</span>
<span id="L786" rel="#L786">786</span>
<span id="L787" rel="#L787">787</span>
<span id="L788" rel="#L788">788</span>
<span id="L789" rel="#L789">789</span>
<span id="L790" rel="#L790">790</span>
<span id="L791" rel="#L791">791</span>
<span id="L792" rel="#L792">792</span>
<span id="L793" rel="#L793">793</span>
<span id="L794" rel="#L794">794</span>
<span id="L795" rel="#L795">795</span>
<span id="L796" rel="#L796">796</span>
<span id="L797" rel="#L797">797</span>
<span id="L798" rel="#L798">798</span>
<span id="L799" rel="#L799">799</span>
<span id="L800" rel="#L800">800</span>
<span id="L801" rel="#L801">801</span>
<span id="L802" rel="#L802">802</span>
<span id="L803" rel="#L803">803</span>
<span id="L804" rel="#L804">804</span>
<span id="L805" rel="#L805">805</span>
<span id="L806" rel="#L806">806</span>
<span id="L807" rel="#L807">807</span>
<span id="L808" rel="#L808">808</span>
<span id="L809" rel="#L809">809</span>
<span id="L810" rel="#L810">810</span>
<span id="L811" rel="#L811">811</span>
<span id="L812" rel="#L812">812</span>
<span id="L813" rel="#L813">813</span>
<span id="L814" rel="#L814">814</span>
<span id="L815" rel="#L815">815</span>
<span id="L816" rel="#L816">816</span>
<span id="L817" rel="#L817">817</span>
<span id="L818" rel="#L818">818</span>
<span id="L819" rel="#L819">819</span>
<span id="L820" rel="#L820">820</span>
<span id="L821" rel="#L821">821</span>
<span id="L822" rel="#L822">822</span>
<span id="L823" rel="#L823">823</span>
<span id="L824" rel="#L824">824</span>
<span id="L825" rel="#L825">825</span>
<span id="L826" rel="#L826">826</span>
<span id="L827" rel="#L827">827</span>
<span id="L828" rel="#L828">828</span>
<span id="L829" rel="#L829">829</span>
<span id="L830" rel="#L830">830</span>
<span id="L831" rel="#L831">831</span>
<span id="L832" rel="#L832">832</span>
<span id="L833" rel="#L833">833</span>
<span id="L834" rel="#L834">834</span>
<span id="L835" rel="#L835">835</span>
<span id="L836" rel="#L836">836</span>
<span id="L837" rel="#L837">837</span>
<span id="L838" rel="#L838">838</span>
<span id="L839" rel="#L839">839</span>
<span id="L840" rel="#L840">840</span>
<span id="L841" rel="#L841">841</span>
<span id="L842" rel="#L842">842</span>
<span id="L843" rel="#L843">843</span>
<span id="L844" rel="#L844">844</span>
<span id="L845" rel="#L845">845</span>
<span id="L846" rel="#L846">846</span>
<span id="L847" rel="#L847">847</span>
<span id="L848" rel="#L848">848</span>
<span id="L849" rel="#L849">849</span>
<span id="L850" rel="#L850">850</span>
<span id="L851" rel="#L851">851</span>
<span id="L852" rel="#L852">852</span>
<span id="L853" rel="#L853">853</span>
<span id="L854" rel="#L854">854</span>
<span id="L855" rel="#L855">855</span>
<span id="L856" rel="#L856">856</span>
<span id="L857" rel="#L857">857</span>
<span id="L858" rel="#L858">858</span>
<span id="L859" rel="#L859">859</span>
<span id="L860" rel="#L860">860</span>
<span id="L861" rel="#L861">861</span>
<span id="L862" rel="#L862">862</span>
<span id="L863" rel="#L863">863</span>
<span id="L864" rel="#L864">864</span>
<span id="L865" rel="#L865">865</span>
<span id="L866" rel="#L866">866</span>
<span id="L867" rel="#L867">867</span>
<span id="L868" rel="#L868">868</span>
<span id="L869" rel="#L869">869</span>
<span id="L870" rel="#L870">870</span>
<span id="L871" rel="#L871">871</span>
<span id="L872" rel="#L872">872</span>
<span id="L873" rel="#L873">873</span>
<span id="L874" rel="#L874">874</span>
<span id="L875" rel="#L875">875</span>
<span id="L876" rel="#L876">876</span>
<span id="L877" rel="#L877">877</span>
<span id="L878" rel="#L878">878</span>
<span id="L879" rel="#L879">879</span>
<span id="L880" rel="#L880">880</span>
<span id="L881" rel="#L881">881</span>
<span id="L882" rel="#L882">882</span>
<span id="L883" rel="#L883">883</span>
<span id="L884" rel="#L884">884</span>
<span id="L885" rel="#L885">885</span>
<span id="L886" rel="#L886">886</span>
<span id="L887" rel="#L887">887</span>
<span id="L888" rel="#L888">888</span>
<span id="L889" rel="#L889">889</span>
<span id="L890" rel="#L890">890</span>
<span id="L891" rel="#L891">891</span>
<span id="L892" rel="#L892">892</span>
<span id="L893" rel="#L893">893</span>
<span id="L894" rel="#L894">894</span>
<span id="L895" rel="#L895">895</span>
<span id="L896" rel="#L896">896</span>
<span id="L897" rel="#L897">897</span>
<span id="L898" rel="#L898">898</span>
<span id="L899" rel="#L899">899</span>
<span id="L900" rel="#L900">900</span>
<span id="L901" rel="#L901">901</span>
<span id="L902" rel="#L902">902</span>
<span id="L903" rel="#L903">903</span>
<span id="L904" rel="#L904">904</span>
<span id="L905" rel="#L905">905</span>
<span id="L906" rel="#L906">906</span>
<span id="L907" rel="#L907">907</span>
<span id="L908" rel="#L908">908</span>
<span id="L909" rel="#L909">909</span>
<span id="L910" rel="#L910">910</span>
<span id="L911" rel="#L911">911</span>
<span id="L912" rel="#L912">912</span>
<span id="L913" rel="#L913">913</span>
<span id="L914" rel="#L914">914</span>
<span id="L915" rel="#L915">915</span>
<span id="L916" rel="#L916">916</span>
<span id="L917" rel="#L917">917</span>
<span id="L918" rel="#L918">918</span>
<span id="L919" rel="#L919">919</span>
<span id="L920" rel="#L920">920</span>
<span id="L921" rel="#L921">921</span>
<span id="L922" rel="#L922">922</span>
<span id="L923" rel="#L923">923</span>
<span id="L924" rel="#L924">924</span>
<span id="L925" rel="#L925">925</span>
<span id="L926" rel="#L926">926</span>
<span id="L927" rel="#L927">927</span>
<span id="L928" rel="#L928">928</span>
<span id="L929" rel="#L929">929</span>
<span id="L930" rel="#L930">930</span>
<span id="L931" rel="#L931">931</span>
<span id="L932" rel="#L932">932</span>
<span id="L933" rel="#L933">933</span>
<span id="L934" rel="#L934">934</span>
<span id="L935" rel="#L935">935</span>
<span id="L936" rel="#L936">936</span>
<span id="L937" rel="#L937">937</span>
<span id="L938" rel="#L938">938</span>
<span id="L939" rel="#L939">939</span>
<span id="L940" rel="#L940">940</span>
<span id="L941" rel="#L941">941</span>
<span id="L942" rel="#L942">942</span>
<span id="L943" rel="#L943">943</span>
<span id="L944" rel="#L944">944</span>
<span id="L945" rel="#L945">945</span>
<span id="L946" rel="#L946">946</span>
<span id="L947" rel="#L947">947</span>
<span id="L948" rel="#L948">948</span>
<span id="L949" rel="#L949">949</span>
<span id="L950" rel="#L950">950</span>
<span id="L951" rel="#L951">951</span>
<span id="L952" rel="#L952">952</span>
<span id="L953" rel="#L953">953</span>
<span id="L954" rel="#L954">954</span>
<span id="L955" rel="#L955">955</span>
<span id="L956" rel="#L956">956</span>
<span id="L957" rel="#L957">957</span>
<span id="L958" rel="#L958">958</span>
<span id="L959" rel="#L959">959</span>
<span id="L960" rel="#L960">960</span>
<span id="L961" rel="#L961">961</span>
<span id="L962" rel="#L962">962</span>
<span id="L963" rel="#L963">963</span>
<span id="L964" rel="#L964">964</span>
<span id="L965" rel="#L965">965</span>
<span id="L966" rel="#L966">966</span>
<span id="L967" rel="#L967">967</span>
<span id="L968" rel="#L968">968</span>
<span id="L969" rel="#L969">969</span>
<span id="L970" rel="#L970">970</span>
<span id="L971" rel="#L971">971</span>
<span id="L972" rel="#L972">972</span>
<span id="L973" rel="#L973">973</span>
<span id="L974" rel="#L974">974</span>
<span id="L975" rel="#L975">975</span>
<span id="L976" rel="#L976">976</span>
<span id="L977" rel="#L977">977</span>
<span id="L978" rel="#L978">978</span>
<span id="L979" rel="#L979">979</span>
<span id="L980" rel="#L980">980</span>
<span id="L981" rel="#L981">981</span>
<span id="L982" rel="#L982">982</span>
<span id="L983" rel="#L983">983</span>
<span id="L984" rel="#L984">984</span>
<span id="L985" rel="#L985">985</span>
<span id="L986" rel="#L986">986</span>
<span id="L987" rel="#L987">987</span>
<span id="L988" rel="#L988">988</span>
<span id="L989" rel="#L989">989</span>
<span id="L990" rel="#L990">990</span>
<span id="L991" rel="#L991">991</span>
<span id="L992" rel="#L992">992</span>
<span id="L993" rel="#L993">993</span>
<span id="L994" rel="#L994">994</span>
<span id="L995" rel="#L995">995</span>
<span id="L996" rel="#L996">996</span>
<span id="L997" rel="#L997">997</span>
<span id="L998" rel="#L998">998</span>
<span id="L999" rel="#L999">999</span>
<span id="L1000" rel="#L1000">1000</span>
<span id="L1001" rel="#L1001">1001</span>
<span id="L1002" rel="#L1002">1002</span>
<span id="L1003" rel="#L1003">1003</span>
<span id="L1004" rel="#L1004">1004</span>
<span id="L1005" rel="#L1005">1005</span>
<span id="L1006" rel="#L1006">1006</span>
<span id="L1007" rel="#L1007">1007</span>
<span id="L1008" rel="#L1008">1008</span>
<span id="L1009" rel="#L1009">1009</span>
<span id="L1010" rel="#L1010">1010</span>
<span id="L1011" rel="#L1011">1011</span>
<span id="L1012" rel="#L1012">1012</span>
<span id="L1013" rel="#L1013">1013</span>
<span id="L1014" rel="#L1014">1014</span>
<span id="L1015" rel="#L1015">1015</span>
<span id="L1016" rel="#L1016">1016</span>
<span id="L1017" rel="#L1017">1017</span>
<span id="L1018" rel="#L1018">1018</span>
<span id="L1019" rel="#L1019">1019</span>
<span id="L1020" rel="#L1020">1020</span>
<span id="L1021" rel="#L1021">1021</span>
<span id="L1022" rel="#L1022">1022</span>
<span id="L1023" rel="#L1023">1023</span>
<span id="L1024" rel="#L1024">1024</span>
<span id="L1025" rel="#L1025">1025</span>
<span id="L1026" rel="#L1026">1026</span>
<span id="L1027" rel="#L1027">1027</span>
<span id="L1028" rel="#L1028">1028</span>
<span id="L1029" rel="#L1029">1029</span>
<span id="L1030" rel="#L1030">1030</span>
<span id="L1031" rel="#L1031">1031</span>
<span id="L1032" rel="#L1032">1032</span>
<span id="L1033" rel="#L1033">1033</span>
<span id="L1034" rel="#L1034">1034</span>
<span id="L1035" rel="#L1035">1035</span>
<span id="L1036" rel="#L1036">1036</span>
<span id="L1037" rel="#L1037">1037</span>
<span id="L1038" rel="#L1038">1038</span>
<span id="L1039" rel="#L1039">1039</span>
<span id="L1040" rel="#L1040">1040</span>
<span id="L1041" rel="#L1041">1041</span>
<span id="L1042" rel="#L1042">1042</span>
<span id="L1043" rel="#L1043">1043</span>
<span id="L1044" rel="#L1044">1044</span>
<span id="L1045" rel="#L1045">1045</span>
<span id="L1046" rel="#L1046">1046</span>
<span id="L1047" rel="#L1047">1047</span>
<span id="L1048" rel="#L1048">1048</span>
<span id="L1049" rel="#L1049">1049</span>
<span id="L1050" rel="#L1050">1050</span>
<span id="L1051" rel="#L1051">1051</span>
<span id="L1052" rel="#L1052">1052</span>
<span id="L1053" rel="#L1053">1053</span>
<span id="L1054" rel="#L1054">1054</span>
<span id="L1055" rel="#L1055">1055</span>
<span id="L1056" rel="#L1056">1056</span>
<span id="L1057" rel="#L1057">1057</span>
<span id="L1058" rel="#L1058">1058</span>
<span id="L1059" rel="#L1059">1059</span>
<span id="L1060" rel="#L1060">1060</span>
<span id="L1061" rel="#L1061">1061</span>
<span id="L1062" rel="#L1062">1062</span>
<span id="L1063" rel="#L1063">1063</span>
<span id="L1064" rel="#L1064">1064</span>
<span id="L1065" rel="#L1065">1065</span>
<span id="L1066" rel="#L1066">1066</span>
<span id="L1067" rel="#L1067">1067</span>
<span id="L1068" rel="#L1068">1068</span>
<span id="L1069" rel="#L1069">1069</span>
<span id="L1070" rel="#L1070">1070</span>
<span id="L1071" rel="#L1071">1071</span>
<span id="L1072" rel="#L1072">1072</span>
<span id="L1073" rel="#L1073">1073</span>
<span id="L1074" rel="#L1074">1074</span>
<span id="L1075" rel="#L1075">1075</span>
<span id="L1076" rel="#L1076">1076</span>
<span id="L1077" rel="#L1077">1077</span>
<span id="L1078" rel="#L1078">1078</span>
<span id="L1079" rel="#L1079">1079</span>
<span id="L1080" rel="#L1080">1080</span>
<span id="L1081" rel="#L1081">1081</span>
<span id="L1082" rel="#L1082">1082</span>
<span id="L1083" rel="#L1083">1083</span>
<span id="L1084" rel="#L1084">1084</span>
<span id="L1085" rel="#L1085">1085</span>
<span id="L1086" rel="#L1086">1086</span>
<span id="L1087" rel="#L1087">1087</span>
<span id="L1088" rel="#L1088">1088</span>
<span id="L1089" rel="#L1089">1089</span>
<span id="L1090" rel="#L1090">1090</span>
<span id="L1091" rel="#L1091">1091</span>
<span id="L1092" rel="#L1092">1092</span>
<span id="L1093" rel="#L1093">1093</span>
<span id="L1094" rel="#L1094">1094</span>
<span id="L1095" rel="#L1095">1095</span>
<span id="L1096" rel="#L1096">1096</span>
<span id="L1097" rel="#L1097">1097</span>
<span id="L1098" rel="#L1098">1098</span>
<span id="L1099" rel="#L1099">1099</span>
<span id="L1100" rel="#L1100">1100</span>
<span id="L1101" rel="#L1101">1101</span>
<span id="L1102" rel="#L1102">1102</span>
<span id="L1103" rel="#L1103">1103</span>
<span id="L1104" rel="#L1104">1104</span>
<span id="L1105" rel="#L1105">1105</span>
<span id="L1106" rel="#L1106">1106</span>
<span id="L1107" rel="#L1107">1107</span>
<span id="L1108" rel="#L1108">1108</span>
<span id="L1109" rel="#L1109">1109</span>
<span id="L1110" rel="#L1110">1110</span>
<span id="L1111" rel="#L1111">1111</span>
<span id="L1112" rel="#L1112">1112</span>
<span id="L1113" rel="#L1113">1113</span>
<span id="L1114" rel="#L1114">1114</span>
<span id="L1115" rel="#L1115">1115</span>
<span id="L1116" rel="#L1116">1116</span>
<span id="L1117" rel="#L1117">1117</span>
<span id="L1118" rel="#L1118">1118</span>
<span id="L1119" rel="#L1119">1119</span>
<span id="L1120" rel="#L1120">1120</span>
<span id="L1121" rel="#L1121">1121</span>
<span id="L1122" rel="#L1122">1122</span>
<span id="L1123" rel="#L1123">1123</span>
<span id="L1124" rel="#L1124">1124</span>
<span id="L1125" rel="#L1125">1125</span>
<span id="L1126" rel="#L1126">1126</span>
<span id="L1127" rel="#L1127">1127</span>
<span id="L1128" rel="#L1128">1128</span>
<span id="L1129" rel="#L1129">1129</span>
<span id="L1130" rel="#L1130">1130</span>
<span id="L1131" rel="#L1131">1131</span>
<span id="L1132" rel="#L1132">1132</span>
<span id="L1133" rel="#L1133">1133</span>
<span id="L1134" rel="#L1134">1134</span>
<span id="L1135" rel="#L1135">1135</span>
<span id="L1136" rel="#L1136">1136</span>
<span id="L1137" rel="#L1137">1137</span>
<span id="L1138" rel="#L1138">1138</span>
<span id="L1139" rel="#L1139">1139</span>
<span id="L1140" rel="#L1140">1140</span>
<span id="L1141" rel="#L1141">1141</span>
<span id="L1142" rel="#L1142">1142</span>
<span id="L1143" rel="#L1143">1143</span>
<span id="L1144" rel="#L1144">1144</span>
<span id="L1145" rel="#L1145">1145</span>
<span id="L1146" rel="#L1146">1146</span>
<span id="L1147" rel="#L1147">1147</span>
<span id="L1148" rel="#L1148">1148</span>
<span id="L1149" rel="#L1149">1149</span>
<span id="L1150" rel="#L1150">1150</span>
<span id="L1151" rel="#L1151">1151</span>
<span id="L1152" rel="#L1152">1152</span>
<span id="L1153" rel="#L1153">1153</span>
<span id="L1154" rel="#L1154">1154</span>
<span id="L1155" rel="#L1155">1155</span>
<span id="L1156" rel="#L1156">1156</span>
<span id="L1157" rel="#L1157">1157</span>
<span id="L1158" rel="#L1158">1158</span>
<span id="L1159" rel="#L1159">1159</span>
<span id="L1160" rel="#L1160">1160</span>
<span id="L1161" rel="#L1161">1161</span>
<span id="L1162" rel="#L1162">1162</span>
<span id="L1163" rel="#L1163">1163</span>
<span id="L1164" rel="#L1164">1164</span>
<span id="L1165" rel="#L1165">1165</span>
<span id="L1166" rel="#L1166">1166</span>
<span id="L1167" rel="#L1167">1167</span>
<span id="L1168" rel="#L1168">1168</span>
<span id="L1169" rel="#L1169">1169</span>
<span id="L1170" rel="#L1170">1170</span>
<span id="L1171" rel="#L1171">1171</span>
<span id="L1172" rel="#L1172">1172</span>
<span id="L1173" rel="#L1173">1173</span>
<span id="L1174" rel="#L1174">1174</span>
<span id="L1175" rel="#L1175">1175</span>
<span id="L1176" rel="#L1176">1176</span>
<span id="L1177" rel="#L1177">1177</span>
<span id="L1178" rel="#L1178">1178</span>
<span id="L1179" rel="#L1179">1179</span>
<span id="L1180" rel="#L1180">1180</span>
<span id="L1181" rel="#L1181">1181</span>
<span id="L1182" rel="#L1182">1182</span>
<span id="L1183" rel="#L1183">1183</span>
<span id="L1184" rel="#L1184">1184</span>
<span id="L1185" rel="#L1185">1185</span>
<span id="L1186" rel="#L1186">1186</span>
<span id="L1187" rel="#L1187">1187</span>
<span id="L1188" rel="#L1188">1188</span>
<span id="L1189" rel="#L1189">1189</span>
<span id="L1190" rel="#L1190">1190</span>
<span id="L1191" rel="#L1191">1191</span>
<span id="L1192" rel="#L1192">1192</span>
<span id="L1193" rel="#L1193">1193</span>
<span id="L1194" rel="#L1194">1194</span>
<span id="L1195" rel="#L1195">1195</span>
<span id="L1196" rel="#L1196">1196</span>
<span id="L1197" rel="#L1197">1197</span>
<span id="L1198" rel="#L1198">1198</span>
<span id="L1199" rel="#L1199">1199</span>
<span id="L1200" rel="#L1200">1200</span>
<span id="L1201" rel="#L1201">1201</span>
<span id="L1202" rel="#L1202">1202</span>
<span id="L1203" rel="#L1203">1203</span>
<span id="L1204" rel="#L1204">1204</span>
<span id="L1205" rel="#L1205">1205</span>
<span id="L1206" rel="#L1206">1206</span>
<span id="L1207" rel="#L1207">1207</span>
<span id="L1208" rel="#L1208">1208</span>
<span id="L1209" rel="#L1209">1209</span>
<span id="L1210" rel="#L1210">1210</span>
<span id="L1211" rel="#L1211">1211</span>
<span id="L1212" rel="#L1212">1212</span>
<span id="L1213" rel="#L1213">1213</span>
<span id="L1214" rel="#L1214">1214</span>
<span id="L1215" rel="#L1215">1215</span>
<span id="L1216" rel="#L1216">1216</span>
<span id="L1217" rel="#L1217">1217</span>
<span id="L1218" rel="#L1218">1218</span>
<span id="L1219" rel="#L1219">1219</span>
<span id="L1220" rel="#L1220">1220</span>
<span id="L1221" rel="#L1221">1221</span>
<span id="L1222" rel="#L1222">1222</span>
<span id="L1223" rel="#L1223">1223</span>
<span id="L1224" rel="#L1224">1224</span>
<span id="L1225" rel="#L1225">1225</span>
<span id="L1226" rel="#L1226">1226</span>
<span id="L1227" rel="#L1227">1227</span>
<span id="L1228" rel="#L1228">1228</span>
<span id="L1229" rel="#L1229">1229</span>
<span id="L1230" rel="#L1230">1230</span>
<span id="L1231" rel="#L1231">1231</span>
<span id="L1232" rel="#L1232">1232</span>
<span id="L1233" rel="#L1233">1233</span>
<span id="L1234" rel="#L1234">1234</span>
<span id="L1235" rel="#L1235">1235</span>
<span id="L1236" rel="#L1236">1236</span>
<span id="L1237" rel="#L1237">1237</span>
<span id="L1238" rel="#L1238">1238</span>
<span id="L1239" rel="#L1239">1239</span>
<span id="L1240" rel="#L1240">1240</span>
<span id="L1241" rel="#L1241">1241</span>
<span id="L1242" rel="#L1242">1242</span>
<span id="L1243" rel="#L1243">1243</span>
<span id="L1244" rel="#L1244">1244</span>
<span id="L1245" rel="#L1245">1245</span>
<span id="L1246" rel="#L1246">1246</span>
<span id="L1247" rel="#L1247">1247</span>
<span id="L1248" rel="#L1248">1248</span>
<span id="L1249" rel="#L1249">1249</span>
<span id="L1250" rel="#L1250">1250</span>

          </td>
          <td class="blob-line-code">
                  <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/**</span></div><div class='line' id='LC2'><span class="cm"> * \file</span></div><div class='line' id='LC3'><span class="cm"> *</span></div><div class='line' id='LC4'><span class="cm"> * \section LICENSE</span></div><div class='line' id='LC5'><span class="cm"> * MIT License (MIT)</span></div><div class='line' id='LC6'><span class="cm"> *</span></div><div class='line' id='LC7'><span class="cm"> * Copyright (c) 2011 VectorNav Technologies, LLC</span></div><div class='line' id='LC8'><span class="cm"> *</span></div><div class='line' id='LC9'><span class="cm"> * Permission is hereby granted, free of charge, to any person obtaining a copy</span></div><div class='line' id='LC10'><span class="cm"> * of this software and associated documentation files (the &quot;Software&quot;), to</span></div><div class='line' id='LC11'><span class="cm"> * deal in the Software without restriction, including without limitation the</span></div><div class='line' id='LC12'><span class="cm"> * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or</span></div><div class='line' id='LC13'><span class="cm"> * sell copies of the Software, and to permit persons to whom the Software is</span></div><div class='line' id='LC14'><span class="cm"> * furnished to do so, subject to the following conditions:</span></div><div class='line' id='LC15'><span class="cm"> *</span></div><div class='line' id='LC16'><span class="cm"> * The above copyright notice and this permission notice shall be included in</span></div><div class='line' id='LC17'><span class="cm"> * all copies or substantial portions of the Software.</span></div><div class='line' id='LC18'><span class="cm"> *</span></div><div class='line' id='LC19'><span class="cm"> * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR</span></div><div class='line' id='LC20'><span class="cm"> * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,</span></div><div class='line' id='LC21'><span class="cm"> * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE</span></div><div class='line' id='LC22'><span class="cm"> * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER</span></div><div class='line' id='LC23'><span class="cm"> * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING</span></div><div class='line' id='LC24'><span class="cm"> * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS</span></div><div class='line' id='LC25'><span class="cm"> * IN THE SOFTWARE.</span></div><div class='line' id='LC26'><span class="cm"> *</span></div><div class='line' id='LC27'><span class="cm"> * \section DESCRIPTION</span></div><div class='line' id='LC28'><span class="cm"> * This header file provides access to devices based on VectorNav&#39;s VN-100</span></div><div class='line' id='LC29'><span class="cm"> * family of orientation sensors.</span></div><div class='line' id='LC30'><span class="cm"> */</span></div><div class='line' id='LC31'><span class="cp">#ifndef _VN100_H_</span></div><div class='line' id='LC32'><span class="cp">#define _VN100_H_</span></div><div class='line' id='LC33'><br/></div><div class='line' id='LC34'><span class="cp">#include &quot;vncp_services.h&quot;</span></div><div class='line' id='LC35'><span class="cp">#include &quot;vn_kinematics.h&quot;</span></div><div class='line' id='LC36'><span class="cp">#include &quot;vn_linearAlgebra.h&quot;</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'><span class="cp">#ifdef __cplusplus</span></div><div class='line' id='LC39'><span class="k">extern</span> <span class="s">&quot;C&quot;</span> <span class="p">{</span></div><div class='line' id='LC40'><span class="cp">#endif</span></div><div class='line' id='LC41'><br/></div><div class='line' id='LC42'><span class="cp">#define VNASYNC_OFF		0		</span><span class="cm">/**&lt; Asynchronous output is turned off. */</span><span class="cp"></span></div><div class='line' id='LC43'><span class="cp">#define VNASYNC_VNYPR	1		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll. */</span><span class="cp"></span></div><div class='line' id='LC44'><span class="cp">#define VNASYNC_VNQTN	2		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion. */</span><span class="cp"></span></div><div class='line' id='LC45'><span class="cp">#define VNASYNC_VNQTM	3		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion and Magnetic. */</span><span class="cp"></span></div><div class='line' id='LC46'><span class="cp">#define VNASYNC_VNQTA	4		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion and Acceleration. */</span><span class="cp"></span></div><div class='line' id='LC47'><span class="cp">#define VNASYNC_VNQTR	5		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion and Angular Rates. */</span><span class="cp"></span></div><div class='line' id='LC48'><span class="cp">#define VNASYNC_VNQMA	6		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion, Magnetic and Acceleration. */</span><span class="cp"></span></div><div class='line' id='LC49'><span class="cp">#define VNASYNC_VNQAR	7		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion, Acceleration and Angular Rates. */</span><span class="cp"></span></div><div class='line' id='LC50'><span class="cp">#define VNASYNC_VNQMR	8		</span><span class="cm">/**&lt; Asynchronous output type is Quaternion, Magnetic, Acceleration and Angular Rates. */</span><span class="cp"></span></div><div class='line' id='LC51'><span class="cp">#define VNASYNC_VNDCM	9		</span><span class="cm">/**&lt; Asynchronous output type is Directional Cosine Orientation Matrix. */</span><span class="cp"></span></div><div class='line' id='LC52'><span class="cp">#define VNASYNC_VNMAG	10		</span><span class="cm">/**&lt; Asynchronous output type is Magnetic Measurements. */</span><span class="cp"></span></div><div class='line' id='LC53'><span class="cp">#define VNASYNC_VNACC	11		</span><span class="cm">/**&lt; Asynchronous output type is Acceleration Measurements. */</span><span class="cp"></span></div><div class='line' id='LC54'><span class="cp">#define VNASYNC_VNGYR	12		</span><span class="cm">/**&lt; Asynchronous output type is Angular Rate Measurements. */</span><span class="cp"></span></div><div class='line' id='LC55'><span class="cp">#define VNASYNC_VNMAR	13		</span><span class="cm">/**&lt; Asynchronous output type is Magnetic, Acceleration, and Angular Rate Measurements. */</span><span class="cp"></span></div><div class='line' id='LC56'><span class="cp">#define VNASYNC_VNYMR	14		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll, Magnetic, Acceleration, and Angular Rate Measurements. */</span><span class="cp"></span></div><div class='line' id='LC57'><span class="cp">#define VNASYNC_VNYCM	15		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll, and Calibrated Measurements. */</span><span class="cp"></span></div><div class='line' id='LC58'><span class="cp">#define VNASYNC_VNYBA	16		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll, Body True Acceleration. */</span><span class="cp"></span></div><div class='line' id='LC59'><span class="cp">#define VNASYNC_VNYIA	17		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll, Inertial True Acceleration. */</span><span class="cp"></span></div><div class='line' id='LC60'><span class="cp">#define VNASYNC_VNICM	18		</span><span class="cm">/**&lt; Asynchronous output type is Yaw, Pitch, Roll, Inertial Magnetic/Acceleration, and Angular Rate Measurements. */</span><span class="cp"></span></div><div class='line' id='LC61'><span class="cp">#define VNASYNC_VNRAW	252		</span><span class="cm">/**&lt; Asynchronous output type is Raw Voltage Measurements. */</span><span class="cp"></span></div><div class='line' id='LC62'><span class="cp">#define VNASYNC_VNCMV	253		</span><span class="cm">/**&lt; Asynchronous output type is Calibrated Measurements. */</span><span class="cp"></span></div><div class='line' id='LC63'><span class="cp">#define VNASYNC_VNSTV	254		</span><span class="cm">/**&lt; Asynchronous output type is Kalman Filter State Vector. */</span><span class="cp"></span></div><div class='line' id='LC64'><span class="cp">#define VNASYNC_VNCOV	255		</span><span class="cm">/**&lt; Asynchronous output type is Kalman Filter Covariance Matrix Diagonal. */</span><span class="cp"></span></div><div class='line' id='LC65'><br/></div><div class='line' id='LC66'><span class="cm">/**</span></div><div class='line' id='LC67'><span class="cm"> * \brief Holds connection information for accessing a VN-100 device.</span></div><div class='line' id='LC68'><span class="cm"> */</span></div><div class='line' id='LC69'><span class="k">typedef</span> <span class="k">struct</span> <span class="p">{</span></div><div class='line' id='LC70'>	<span class="kt">char</span><span class="o">*</span>	<span class="n">portName</span><span class="p">;</span>		<span class="cm">/**&lt; The name of the serial port. */</span></div><div class='line' id='LC71'>	<span class="kt">int</span>		<span class="n">baudRate</span><span class="p">;</span>		<span class="cm">/**&lt; The baudrate of the serial port. */</span></div><div class='line' id='LC72'>	<span class="n">VN_BOOL</span>	<span class="n">isConnected</span><span class="p">;</span>	<span class="cm">/**&lt; Inidicates if the serial port is open. */</span></div><div class='line' id='LC73'>	<span class="kt">void</span><span class="o">*</span>	<span class="n">internalData</span><span class="p">;</span>	<span class="cm">/**&lt; Pointer to data used internally by the Vn100 function handlers. */</span></div><div class='line' id='LC74'><span class="p">}</span> <span class="n">Vn100</span><span class="p">;</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'><span class="cm">/**</span></div><div class='line' id='LC77'><span class="cm"> * \brief Composite structure of the various asynchronous data the VN-100 device</span></div><div class='line' id='LC78'><span class="cm"> * is capable of outputting.</span></div><div class='line' id='LC79'><span class="cm"> */</span></div><div class='line' id='LC80'><span class="k">typedef</span> <span class="k">struct</span> <span class="p">{</span></div><div class='line' id='LC81'>	<span class="n">VnYpr</span>			<span class="n">ypr</span><span class="p">;</span>						<span class="cm">/**&lt; Yaw, pitch, roll. */</span></div><div class='line' id='LC82'>	<span class="n">VnQuaternion</span>	<span class="n">quaternion</span><span class="p">;</span>					<span class="cm">/**&lt; Quaternion. */</span></div><div class='line' id='LC83'>	<span class="n">VnVector3</span>		<span class="n">magnetic</span><span class="p">;</span>					<span class="cm">/**&lt; Magnetic measurements. */</span></div><div class='line' id='LC84'>	<span class="n">VnVector3</span>		<span class="n">acceleration</span><span class="p">;</span>				<span class="cm">/**&lt; Acceleration measurements. */</span></div><div class='line' id='LC85'>	<span class="n">VnVector3</span>		<span class="n">angularRate</span><span class="p">;</span>				<span class="cm">/**&lt; Angular rate / gyro measurements. */</span></div><div class='line' id='LC86'>	<span class="n">VnMatrix3x3</span>		<span class="n">dcm</span><span class="p">;</span>						<span class="cm">/**&lt; Direction cosine matrix. */</span></div><div class='line' id='LC87'>	<span class="kt">double</span>			<span class="n">temperature</span><span class="p">;</span>				<span class="cm">/**&lt; Temperature. */</span></div><div class='line' id='LC88'>	<span class="n">VnVector3</span>		<span class="n">magneticVoltage</span><span class="p">;</span>			<span class="cm">/**&lt; Magnetic sensor voltages. */</span></div><div class='line' id='LC89'>	<span class="n">VnVector3</span>		<span class="n">accelerationVoltage</span><span class="p">;</span>		<span class="cm">/**&lt; Accleration sensor voltages. */</span></div><div class='line' id='LC90'>	<span class="n">VnVector3</span>		<span class="n">angularRateVoltage</span><span class="p">;</span>			<span class="cm">/**&lt; Angular rate sensor voltages. */</span></div><div class='line' id='LC91'>	<span class="kt">double</span>			<span class="n">temperatureVoltage</span><span class="p">;</span>			<span class="cm">/**&lt; Temperatue sensor voltages. */</span></div><div class='line' id='LC92'>	<span class="n">VnVector3</span>		<span class="n">angularRateBias</span><span class="p">;</span>			<span class="cm">/**&lt; Angular rate estimated biases. */</span></div><div class='line' id='LC93'>	<span class="n">VnVector3</span>		<span class="n">attitudeVariance</span><span class="p">;</span>			<span class="cm">/**&lt; Variance for the computed attitude. */</span></div><div class='line' id='LC94'>	<span class="n">VnVector3</span>		<span class="n">angularRateBiasVariance</span><span class="p">;</span>	<span class="cm">/**&lt; Angular rate bias variance. */</span></div><div class='line' id='LC95'><span class="p">}</span> <span class="n">Vn100CompositeData</span><span class="p">;</span></div><div class='line' id='LC96'><br/></div><div class='line' id='LC97'><span class="cm">/**</span></div><div class='line' id='LC98'><span class="cm"> * \brief Fuction type used for receiving notifications of when new asynchronous</span></div><div class='line' id='LC99'><span class="cm"> * data is received.</span></div><div class='line' id='LC100'><span class="cm"> *</span></div><div class='line' id='LC101'><span class="cm"> * \param[in]	sender	The device that sent the notification.</span></div><div class='line' id='LC102'><span class="cm"> * \param[in]	newData	Pointer to the new data.</span></div><div class='line' id='LC103'><span class="cm"> */</span></div><div class='line' id='LC104'><span class="k">typedef</span> <span class="nf">void</span> <span class="p">(</span><span class="o">*</span><span class="n">Vn100NewAsyncDataReceivedListener</span><span class="p">)(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">sender</span><span class="p">,</span> <span class="n">Vn100CompositeData</span><span class="o">*</span> <span class="n">newData</span><span class="p">);</span></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'><span class="cm">/**</span></div><div class='line' id='LC107'><span class="cm"> * \brief Connects to a VectorNav VN-100 device.</span></div><div class='line' id='LC108'><span class="cm"> *</span></div><div class='line' id='LC109'><span class="cm"> * \param[out]	newVn100	An uninitialized Vn100 control object should be passed in.</span></div><div class='line' id='LC110'><span class="cm"> * \param[in]	portName	The name of the COM port to connect to.</span></div><div class='line' id='LC111'><span class="cm"> * \param[in]	baudrate	The baudrate to connect at.</span></div><div class='line' id='LC112'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC113'><span class="cm"> */</span></div><div class='line' id='LC114'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_connect</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">newVn100</span><span class="p">,</span> <span class="k">const</span> <span class="kt">char</span><span class="o">*</span> <span class="n">portName</span><span class="p">,</span> <span class="kt">int</span> <span class="n">baudrate</span><span class="p">);</span></div><div class='line' id='LC115'><br/></div><div class='line' id='LC116'><span class="cm">/**</span></div><div class='line' id='LC117'><span class="cm"> * \brief Disconnects from the VN-100 device and disposes of any internal resources.</span></div><div class='line' id='LC118'><span class="cm"> *</span></div><div class='line' id='LC119'><span class="cm"> * \param vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC120'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC121'><span class="cm"> */</span></div><div class='line' id='LC122'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_disconnect</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">);</span></div><div class='line' id='LC123'><br/></div><div class='line' id='LC124'><span class="cm">/**</span></div><div class='line' id='LC125'><span class="cm"> * \brief Computes the checksum for the provided command.</span></div><div class='line' id='LC126'><span class="cm"> *</span></div><div class='line' id='LC127'><span class="cm"> * \param[in]	cmdToCheck</span></div><div class='line' id='LC128'><span class="cm"> * Null-terminated string of the form &quot;VNRRG,1&quot;.</span></div><div class='line' id='LC129'><span class="cm"> *</span></div><div class='line' id='LC130'><span class="cm"> * \return The computed checksum number.</span></div><div class='line' id='LC131'><span class="cm"> */</span></div><div class='line' id='LC132'><span class="kt">unsigned</span> <span class="kt">char</span> <span class="nf">vn100_checksum_compute</span><span class="p">(</span><span class="k">const</span> <span class="kt">char</span><span class="o">*</span> <span class="n">cmdToCheck</span><span class="p">);</span></div><div class='line' id='LC133'><br/></div><div class='line' id='LC134'><span class="cm">/**</span></div><div class='line' id='LC135'><span class="cm"> * \brief Computes the checksum for the provided command and returns it as a</span></div><div class='line' id='LC136'><span class="cm"> * two character string representing it in hexidecimal.</span></div><div class='line' id='LC137'><span class="cm"> *</span></div><div class='line' id='LC138'><span class="cm"> * \param[in]	cmdToCheck</span></div><div class='line' id='LC139'><span class="cm"> * Null-terminated string of the form &quot;VNRRG,1&quot;.</span></div><div class='line' id='LC140'><span class="cm"> *</span></div><div class='line' id='LC141'><span class="cm"> * \param[out]	checksum</span></div><div class='line' id='LC142'><span class="cm"> * A character array of length 2 which the computed checksum will be placed.</span></div><div class='line' id='LC143'><span class="cm"> */</span></div><div class='line' id='LC144'><span class="kt">void</span> <span class="nf">vn100_checksum_computeAndReturnAsHex</span><span class="p">(</span><span class="k">const</span> <span class="kt">char</span><span class="o">*</span> <span class="n">cmdToCheck</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">checksum</span><span class="p">);</span></div><div class='line' id='LC145'><br/></div><div class='line' id='LC146'><span class="cm">/**</span></div><div class='line' id='LC147'><span class="cm"> * \brief Sets the timeout value for the reading values from the VN-100 sensor.</span></div><div class='line' id='LC148'><span class="cm"> *</span></div><div class='line' id='LC149'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC150'><span class="cm"> * \param[in] timeout The timeout value in milliseconds. Specify -1 to not use</span></div><div class='line' id='LC151'><span class="cm"> * any timeouts.</span></div><div class='line' id='LC152'><span class="cm"> *</span></div><div class='line' id='LC153'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC154'><span class="cm"> */</span></div><div class='line' id='LC155'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_set_timeout</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">int</span> <span class="n">timeout</span><span class="p">);</span></div><div class='line' id='LC156'><br/></div><div class='line' id='LC157'><span class="cm">/**</span></div><div class='line' id='LC158'><span class="cm"> * \brief Retrieves the associated timeout value for the Vn100 object.</span></div><div class='line' id='LC159'><span class="cm"> *</span></div><div class='line' id='LC160'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC161'><span class="cm"> *</span></div><div class='line' id='LC162'><span class="cm"> * \return The timeout value in milliseconds. -1 indicates that timeouts are</span></div><div class='line' id='LC163'><span class="cm"> * not used.</span></div><div class='line' id='LC164'><span class="cm"> */</span></div><div class='line' id='LC165'><span class="kt">int</span> <span class="nf">vn100_get_timeout</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">);</span></div><div class='line' id='LC166'><br/></div><div class='line' id='LC167'><span class="cm">/**</span></div><div class='line' id='LC168'><span class="cm"> * \brief Retreives the most recently received asynchronous measurements</span></div><div class='line' id='LC169'><span class="cm"> * received from the VN-100 device.</span></div><div class='line' id='LC170'><span class="cm"> *</span></div><div class='line' id='LC171'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC172'><span class="cm"> * \param[out]	curData</span></div><div class='line' id='LC173'><span class="cm"> * Composite of the last currently received data from the device. If there was</span></div><div class='line' id='LC174'><span class="cm"> * no data received for certain fields, they will be zeroed out.</span></div><div class='line' id='LC175'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC176'><span class="cm"> */</span></div><div class='line' id='LC177'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getCurrentAsyncData</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">Vn100CompositeData</span><span class="o">*</span> <span class="n">curData</span><span class="p">);</span></div><div class='line' id='LC178'><br/></div><div class='line' id='LC179'><span class="cm">/**</span></div><div class='line' id='LC180'><span class="cm"> * \brief Commands the VN-100 unit to write its current register setting to</span></div><div class='line' id='LC181'><span class="cm"> * non-volatile memory.</span></div><div class='line' id='LC182'><span class="cm"> *</span></div><div class='line' id='LC183'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC184'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC185'><span class="cm"> */</span></div><div class='line' id='LC186'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_writeSettings</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC187'><br/></div><div class='line' id='LC188'><span class="cm">/**</span></div><div class='line' id='LC189'><span class="cm"> * \brief Commands the VN-100 unit to revert its settings to factory defaults.</span></div><div class='line' id='LC190'><span class="cm"> *</span></div><div class='line' id='LC191'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC192'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC193'><span class="cm"> */</span></div><div class='line' id='LC194'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_restoreFactorySettings</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC195'><br/></div><div class='line' id='LC196'><span class="cm">/**</span></div><div class='line' id='LC197'><span class="cm"> * \brief Commands the VN-100 module to zero out its current orientation.</span></div><div class='line' id='LC198'><span class="cm"> *</span></div><div class='line' id='LC199'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC200'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC201'><span class="cm"> */</span></div><div class='line' id='LC202'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_tare</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC203'><br/></div><div class='line' id='LC204'><span class="cm">/**</span></div><div class='line' id='LC205'><span class="cm"> * \brief Commands the VN-100 module to reset itself.</span></div><div class='line' id='LC206'><span class="cm"> *</span></div><div class='line' id='LC207'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC208'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC209'><span class="cm"> */</span></div><div class='line' id='LC210'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_reset</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">);</span></div><div class='line' id='LC211'><br/></div><div class='line' id='LC212'><span class="cm">/**</span></div><div class='line' id='LC213'><span class="cm"> * \brief Notifies the VN-100 module if a known magnetic disturbance is present.</span></div><div class='line' id='LC214'><span class="cm"> *</span></div><div class='line' id='LC215'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC216'><span class="cm"> * \param[in] isDisturbancePresent True if a known magnetic disturbance is present. False if not.</span></div><div class='line' id='LC217'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC218'><span class="cm"> */</span></div><div class='line' id='LC219'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_knownMagneticDisturbance</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">isDisturbancePresent</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC220'><br/></div><div class='line' id='LC221'><span class="cm">/**</span></div><div class='line' id='LC222'><span class="cm"> * \brief Notifies the VN-100 module if a known acceleration disturbance is present.</span></div><div class='line' id='LC223'><span class="cm"> *</span></div><div class='line' id='LC224'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC225'><span class="cm"> * \param[in] isDisturbancePresent True if a known acceleration disturbance is present. False if not.</span></div><div class='line' id='LC226'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC227'><span class="cm"> */</span></div><div class='line' id='LC228'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_knownAccelerationDisturbance</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">isDisturbancePresent</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC229'><br/></div><div class='line' id='LC230'><span class="cm">/**</span></div><div class='line' id='LC231'><span class="cm"> * \brief Commands the VN-100 module to save the current gyro bias estimate to</span></div><div class='line' id='LC232'><span class="cm"> * memory for use on the next module startup.</span></div><div class='line' id='LC233'><span class="cm"> *</span></div><div class='line' id='LC234'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC235'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC236'><span class="cm"> */</span></div><div class='line' id='LC237'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setGyroBias</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC238'><br/></div><div class='line' id='LC239'><span class="cm">/**</span></div><div class='line' id='LC240'><span class="cm"> * \brief Allows registering a function which will be called whenever a new</span></div><div class='line' id='LC241'><span class="cm"> * asynchronous data packet is received from the VN-100 module.</span></div><div class='line' id='LC242'><span class="cm"> *</span></div><div class='line' id='LC243'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC244'><span class="cm"> * </span></div><div class='line' id='LC245'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC246'><span class="cm"> */</span></div><div class='line' id='LC247'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_registerAsyncDataReceivedListener</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">Vn100NewAsyncDataReceivedListener</span> <span class="n">listener</span><span class="p">);</span></div><div class='line' id='LC248'><br/></div><div class='line' id='LC249'><span class="cm">/**</span></div><div class='line' id='LC250'><span class="cm"> * \brief Unregisters an already registered function for recieving notifications</span></div><div class='line' id='LC251'><span class="cm"> * of when new asynchronous data is received.</span></div><div class='line' id='LC252'><span class="cm"> *</span></div><div class='line' id='LC253'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC254'><span class="cm"> * </span></div><div class='line' id='LC255'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC256'><span class="cm"> */</span></div><div class='line' id='LC257'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_unregisterAsyncDataReceivedListener</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">Vn100NewAsyncDataReceivedListener</span> <span class="n">listener</span><span class="p">);</span></div><div class='line' id='LC258'><br/></div><div class='line' id='LC259'><span class="cm">/**</span></div><div class='line' id='LC260'><span class="cm"> * \brief Checks if we are able to send and receive communication with the VN-100 sensor.</span></div><div class='line' id='LC261'><span class="cm"> *</span></div><div class='line' id='LC262'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC263'><span class="cm"> *</span></div><div class='line' id='LC264'><span class="cm"> * \return VN_TRUE if the library was able to send and receive a valid response from the VN-100 sensor; otherwise VN_FALSE.</span></div><div class='line' id='LC265'><span class="cm"> */</span></div><div class='line' id='LC266'><span class="n">VN_BOOL</span> <span class="nf">vn100_verifyConnectivity</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">);</span></div><div class='line' id='LC267'><br/></div><div class='line' id='LC268'><span class="cm">/* VN100_CODE_GENERATION_SPOT_0_START */</span></div><div class='line' id='LC269'><br/></div><div class='line' id='LC270'><span class="cm">/**</span></div><div class='line' id='LC271'><span class="cm"> * \brief Gets the values in the User Tag register.</span></div><div class='line' id='LC272'><span class="cm"> *</span></div><div class='line' id='LC273'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC274'><span class="cm"> * \param[out] userTagBuffer Buffer to store the response. Must have a length of at least 21 characters.</span></div><div class='line' id='LC275'><span class="cm"> * \param[in] userTagBufferLength Length of the provided userTagBuffer buffer.</span></div><div class='line' id='LC276'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC277'><span class="cm"> */</span></div><div class='line' id='LC278'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getUserTag</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">userTagBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">userTagBufferLength</span><span class="p">);</span></div><div class='line' id='LC279'><br/></div><div class='line' id='LC280'><span class="cm">/**</span></div><div class='line' id='LC281'><span class="cm"> * \brief Sets the values of the User Tag register.</span></div><div class='line' id='LC282'><span class="cm"> *</span></div><div class='line' id='LC283'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC284'><span class="cm"> * \param[in] userTagData Array containg the data to send. Length must be equal to or less than 20 characters.</span></div><div class='line' id='LC285'><span class="cm"> * \param[in] userTagDataLength Length of the data to send in the userTagData array.</span></div><div class='line' id='LC286'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC287'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC288'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC289'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC290'><span class="cm"> */</span></div><div class='line' id='LC291'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setUserTag</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">userTagData</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">userTagDataLength</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC292'><br/></div><div class='line' id='LC293'><span class="cm">/**</span></div><div class='line' id='LC294'><span class="cm"> * \brief Gets the values in the Model Number register.</span></div><div class='line' id='LC295'><span class="cm"> *</span></div><div class='line' id='LC296'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC297'><span class="cm"> * \param[out] modelBuffer Buffer to store the response. Must have a length of at least 25 characters.</span></div><div class='line' id='LC298'><span class="cm"> * \param[in] modelBufferLength Length of the provided modelBuffer buffer.</span></div><div class='line' id='LC299'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC300'><span class="cm"> */</span></div><div class='line' id='LC301'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getModelNumber</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">modelBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">modelBufferLength</span><span class="p">);</span></div><div class='line' id='LC302'><br/></div><div class='line' id='LC303'><span class="cm">/**</span></div><div class='line' id='LC304'><span class="cm"> * \brief Gets the values in the Hardware Revision register.</span></div><div class='line' id='LC305'><span class="cm"> *</span></div><div class='line' id='LC306'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC307'><span class="cm"> * \param[out] hardwareRevision The hardware revision value of the sensor.</span></div><div class='line' id='LC308'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC309'><span class="cm"> */</span></div><div class='line' id='LC310'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getHardwareRevision</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">int</span><span class="o">*</span> <span class="n">hardwareRevision</span><span class="p">);</span></div><div class='line' id='LC311'><br/></div><div class='line' id='LC312'><span class="cm">/**</span></div><div class='line' id='LC313'><span class="cm"> * \brief Gets the values in the Serial Number register.</span></div><div class='line' id='LC314'><span class="cm"> *</span></div><div class='line' id='LC315'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC316'><span class="cm"> * \param[out] serialNumberBuffer Buffer to store the response. Must have a length of at least 25 characters.</span></div><div class='line' id='LC317'><span class="cm"> * \param[in] serialNumberBufferLength Length of the provided serialNumberBuffer buffer.</span></div><div class='line' id='LC318'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC319'><span class="cm"> */</span></div><div class='line' id='LC320'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getSerialNumber</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">serialNumberBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">serialNumberBufferLength</span><span class="p">);</span></div><div class='line' id='LC321'><br/></div><div class='line' id='LC322'><span class="cm">/**</span></div><div class='line' id='LC323'><span class="cm"> * \brief Gets the values in the Firmware Version register.</span></div><div class='line' id='LC324'><span class="cm"> *</span></div><div class='line' id='LC325'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC326'><span class="cm"> * \param[out] firmwareVersionBuffer Buffer to store the response. Must have a length of at least 16 characters.</span></div><div class='line' id='LC327'><span class="cm"> * \param[in] firmwareVersionBufferLength Length of the provided firmwareVersionBuffer buffer.</span></div><div class='line' id='LC328'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC329'><span class="cm"> */</span></div><div class='line' id='LC330'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getFirmwareVersion</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">firmwareVersionBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">firmwareVersionBufferLength</span><span class="p">);</span></div><div class='line' id='LC331'><br/></div><div class='line' id='LC332'><span class="cm">/**</span></div><div class='line' id='LC333'><span class="cm"> * \brief Gets the values in the Serial Baud Rate register.</span></div><div class='line' id='LC334'><span class="cm"> *</span></div><div class='line' id='LC335'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC336'><span class="cm"> * \param[out] serialBaudrate The serial baudrate value of the sensor.</span></div><div class='line' id='LC337'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC338'><span class="cm"> */</span></div><div class='line' id='LC339'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getSerialBaudRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">serialBaudrate</span><span class="p">);</span></div><div class='line' id='LC340'><br/></div><div class='line' id='LC341'><span class="cm">/**</span></div><div class='line' id='LC342'><span class="cm"> * \brief Sets the values of the Serial Baud Rate register.</span></div><div class='line' id='LC343'><span class="cm"> *</span></div><div class='line' id='LC344'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC345'><span class="cm"> * \param[in] serialBaudrate Value for the serial baudrate field.</span></div><div class='line' id='LC346'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC347'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC348'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC349'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC350'><span class="cm"> */</span></div><div class='line' id='LC351'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setSerialBaudRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">serialBaudrate</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC352'><br/></div><div class='line' id='LC353'><span class="cm">/**</span></div><div class='line' id='LC354'><span class="cm"> * \brief Gets the values in the Asynchronous Data Output Type register.</span></div><div class='line' id='LC355'><span class="cm"> *</span></div><div class='line' id='LC356'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC357'><span class="cm"> * \param[out] asyncDataOutputType The asynchronous data output type value of the sensor.</span></div><div class='line' id='LC358'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC359'><span class="cm"> */</span></div><div class='line' id='LC360'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAsynchronousDataOutputType</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">asyncDataOutputType</span><span class="p">);</span></div><div class='line' id='LC361'><br/></div><div class='line' id='LC362'><span class="cm">/**</span></div><div class='line' id='LC363'><span class="cm"> * \brief Sets the values of the Asynchronous Data Output Type register.</span></div><div class='line' id='LC364'><span class="cm"> *</span></div><div class='line' id='LC365'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC366'><span class="cm"> * \param[in] asyncDataOutputType Value for the asynchronous data output type field.</span></div><div class='line' id='LC367'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC368'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC369'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC370'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC371'><span class="cm"> */</span></div><div class='line' id='LC372'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setAsynchronousDataOutputType</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">asyncDataOutputType</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC373'><br/></div><div class='line' id='LC374'><span class="cm">/**</span></div><div class='line' id='LC375'><span class="cm"> * \brief Gets the values in the Asynchronous Data Output Frequency register.</span></div><div class='line' id='LC376'><span class="cm"> *</span></div><div class='line' id='LC377'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC378'><span class="cm"> * \param[out] asyncDataOutputFrequency The asynchronous data output frequency value of the sensor.</span></div><div class='line' id='LC379'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC380'><span class="cm"> */</span></div><div class='line' id='LC381'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAsynchronousDataOutputFrequency</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">asyncDataOutputFrequency</span><span class="p">);</span></div><div class='line' id='LC382'><br/></div><div class='line' id='LC383'><span class="cm">/**</span></div><div class='line' id='LC384'><span class="cm"> * \brief Sets the values of the Asynchronous Data Output Frequency register.</span></div><div class='line' id='LC385'><span class="cm"> *</span></div><div class='line' id='LC386'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC387'><span class="cm"> * \param[in] asyncDataOutputFrequency Value for the asynchronous data output frequency field.</span></div><div class='line' id='LC388'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC389'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC390'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC391'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC392'><span class="cm"> */</span></div><div class='line' id='LC393'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setAsynchronousDataOutputFrequency</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">asyncDataOutputFrequency</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC394'><br/></div><div class='line' id='LC395'><span class="cm">/**</span></div><div class='line' id='LC396'><span class="cm"> * \brief Gets the values in the Attitude (Yaw, Pitch, Roll) register.</span></div><div class='line' id='LC397'><span class="cm"> *</span></div><div class='line' id='LC398'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC399'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC400'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC401'><span class="cm"> */</span></div><div class='line' id='LC402'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRoll</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">);</span></div><div class='line' id='LC403'><br/></div><div class='line' id='LC404'><span class="cm">/**</span></div><div class='line' id='LC405'><span class="cm"> * \brief Gets the values in the Attitude (Quaternion) register.</span></div><div class='line' id='LC406'><span class="cm"> *</span></div><div class='line' id='LC407'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC408'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC409'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC410'><span class="cm"> */</span></div><div class='line' id='LC411'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternion</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">);</span></div><div class='line' id='LC412'><br/></div><div class='line' id='LC413'><span class="cm">/**</span></div><div class='line' id='LC414'><span class="cm"> * \brief Gets the values in the Quaternion and Magnetic register.</span></div><div class='line' id='LC415'><span class="cm"> *</span></div><div class='line' id='LC416'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC417'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC418'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC419'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC420'><span class="cm"> */</span></div><div class='line' id='LC421'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionMagnetic</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">);</span></div><div class='line' id='LC422'><br/></div><div class='line' id='LC423'><span class="cm">/**</span></div><div class='line' id='LC424'><span class="cm"> * \brief Gets the values in the Quaternion and Acceleration register.</span></div><div class='line' id='LC425'><span class="cm"> *</span></div><div class='line' id='LC426'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC427'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC428'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC429'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC430'><span class="cm"> */</span></div><div class='line' id='LC431'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionAcceleration</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">);</span></div><div class='line' id='LC432'><br/></div><div class='line' id='LC433'><span class="cm">/**</span></div><div class='line' id='LC434'><span class="cm"> * \brief Gets the values in the Quaternion and Angular Rates register.</span></div><div class='line' id='LC435'><span class="cm"> *</span></div><div class='line' id='LC436'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC437'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC438'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC439'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC440'><span class="cm"> */</span></div><div class='line' id='LC441'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC442'><br/></div><div class='line' id='LC443'><span class="cm">/**</span></div><div class='line' id='LC444'><span class="cm"> * \brief Gets the values in the Quaternion, Magnetic and Acceleration register.</span></div><div class='line' id='LC445'><span class="cm"> *</span></div><div class='line' id='LC446'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC447'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC448'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC449'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC450'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC451'><span class="cm"> */</span></div><div class='line' id='LC452'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionMagneticAcceleration</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">);</span></div><div class='line' id='LC453'><br/></div><div class='line' id='LC454'><span class="cm">/**</span></div><div class='line' id='LC455'><span class="cm"> * \brief Gets the values in the Quaternion, Acceleration and Angular Rates register.</span></div><div class='line' id='LC456'><span class="cm"> *</span></div><div class='line' id='LC457'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC458'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC459'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC460'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC461'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC462'><span class="cm"> */</span></div><div class='line' id='LC463'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionAccelerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC464'><br/></div><div class='line' id='LC465'><span class="cm">/**</span></div><div class='line' id='LC466'><span class="cm"> * \brief Gets the values in the Quaternion, Magnetic, Acceleration and Angular Rates register.</span></div><div class='line' id='LC467'><span class="cm"> *</span></div><div class='line' id='LC468'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC469'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC470'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC471'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC472'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC473'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC474'><span class="cm"> */</span></div><div class='line' id='LC475'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getQuaternionMagneticAcclerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC476'><br/></div><div class='line' id='LC477'><span class="cm">/**</span></div><div class='line' id='LC478'><span class="cm"> * \brief Gets the values in the Attitude (Directional Cosine Matrix) register.</span></div><div class='line' id='LC479'><span class="cm"> *</span></div><div class='line' id='LC480'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC481'><span class="cm"> * \param[out] attitude The current sensor attitude (DCM) values.</span></div><div class='line' id='LC482'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC483'><span class="cm"> */</span></div><div class='line' id='LC484'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getDirectionCosineMatrix</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span><span class="o">*</span> <span class="n">attitude</span><span class="p">);</span></div><div class='line' id='LC485'><br/></div><div class='line' id='LC486'><span class="cm">/**</span></div><div class='line' id='LC487'><span class="cm"> * \brief Gets the values in the Magnetic Measurements register.</span></div><div class='line' id='LC488'><span class="cm"> *</span></div><div class='line' id='LC489'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC490'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC491'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC492'><span class="cm"> */</span></div><div class='line' id='LC493'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagnetic</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">);</span></div><div class='line' id='LC494'><br/></div><div class='line' id='LC495'><span class="cm">/**</span></div><div class='line' id='LC496'><span class="cm"> * \brief Gets the values in the Acceleration Measurements register.</span></div><div class='line' id='LC497'><span class="cm"> *</span></div><div class='line' id='LC498'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC499'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC500'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC501'><span class="cm"> */</span></div><div class='line' id='LC502'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAcceleration</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">);</span></div><div class='line' id='LC503'><br/></div><div class='line' id='LC504'><span class="cm">/**</span></div><div class='line' id='LC505'><span class="cm"> * \brief Gets the values in the Angular Rate Measurements register.</span></div><div class='line' id='LC506'><span class="cm"> *</span></div><div class='line' id='LC507'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC508'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC509'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC510'><span class="cm"> */</span></div><div class='line' id='LC511'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC512'><br/></div><div class='line' id='LC513'><span class="cm">/**</span></div><div class='line' id='LC514'><span class="cm"> * \brief Gets the values in the Magnetic, Acceleration and Angular Rates register.</span></div><div class='line' id='LC515'><span class="cm"> *</span></div><div class='line' id='LC516'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC517'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC518'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC519'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC520'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC521'><span class="cm"> */</span></div><div class='line' id='LC522'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagneticAccelerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC523'><br/></div><div class='line' id='LC524'><span class="cm">/**</span></div><div class='line' id='LC525'><span class="cm"> * \brief Gets the values in the Magnetic and Gravity Reference Vectors register.</span></div><div class='line' id='LC526'><span class="cm"> *</span></div><div class='line' id='LC527'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC528'><span class="cm"> * \param[out] magneticReference The current sensor magnetic reference vector (X,Y,Z) values.</span></div><div class='line' id='LC529'><span class="cm"> * \param[out] gravityReference The current sensor gravity reference vector (X,Y,Z) values.</span></div><div class='line' id='LC530'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC531'><span class="cm"> */</span></div><div class='line' id='LC532'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagneticGravityReferenceVectors</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magneticReference</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">gravityReference</span><span class="p">);</span></div><div class='line' id='LC533'><br/></div><div class='line' id='LC534'><span class="cm">/**</span></div><div class='line' id='LC535'><span class="cm"> * \brief Sets the values of the Magnetic and Gravity Reference Vectors register.</span></div><div class='line' id='LC536'><span class="cm"> *</span></div><div class='line' id='LC537'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC538'><span class="cm"> * \param[in] magneticReference The magnetic reference vector (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC539'><span class="cm"> * \param[in] gravityReference The gravity reference vector (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC540'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC541'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC542'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC543'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC544'><span class="cm"> */</span></div><div class='line' id='LC545'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setMagneticGravityReferenceVectors</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">magneticReference</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">gravityReference</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC546'><br/></div><div class='line' id='LC547'><span class="cm">/**</span></div><div class='line' id='LC548'><span class="cm"> * \brief Gets the values in the Filter Measurement Variance Parameters register.</span></div><div class='line' id='LC549'><span class="cm"> *</span></div><div class='line' id='LC550'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC551'><span class="cm"> * \param[out] angularWalkVariance The angular walk variance value of the sensor.</span></div><div class='line' id='LC552'><span class="cm"> * \param[out] angularRateVariance The current sensor angular rate variance (X,Y,Z) values.</span></div><div class='line' id='LC553'><span class="cm"> * \param[out] magneticVariance The current sensor magnetic variance (X,Y,Z) values.</span></div><div class='line' id='LC554'><span class="cm"> * \param[out] accelerationVariance The current sensor acceleration variance (X,Y,Z) values.</span></div><div class='line' id='LC555'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC556'><span class="cm"> */</span></div><div class='line' id='LC557'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getFilterMeasurementVarianceParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">angularWalkVariance</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRateVariance</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magneticVariance</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">accelerationVariance</span><span class="p">);</span></div><div class='line' id='LC558'><br/></div><div class='line' id='LC559'><span class="cm">/**</span></div><div class='line' id='LC560'><span class="cm"> * \brief Sets the values of the Filter Measurement Variance Parameters register.</span></div><div class='line' id='LC561'><span class="cm"> *</span></div><div class='line' id='LC562'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC563'><span class="cm"> * \param[in] angularWalkVariance Value for the angular walk variance field.</span></div><div class='line' id='LC564'><span class="cm"> * \param[in] angularRateVariance The angular rate variance (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC565'><span class="cm"> * \param[in] magneticVariance The magnetic variance (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC566'><span class="cm"> * \param[in] accelerationVariance The acceleration variance (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC567'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC568'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC569'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC570'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC571'><span class="cm"> */</span></div><div class='line' id='LC572'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setFilterMeasurementVarianceParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span> <span class="n">angularWalkVariance</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">angularRateVariance</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">magneticVariance</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">accelerationVariance</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC573'><br/></div><div class='line' id='LC574'><span class="cm">/**</span></div><div class='line' id='LC575'><span class="cm"> * \brief Gets the values in the Magnetic Hard/Soft Iron Compensation Parameters register.</span></div><div class='line' id='LC576'><span class="cm"> *</span></div><div class='line' id='LC577'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC578'><span class="cm"> * \param[out] c The current sensor C matrix values.</span></div><div class='line' id='LC579'><span class="cm"> * \param[out] b The current sensor B vector values.</span></div><div class='line' id='LC580'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC581'><span class="cm"> */</span></div><div class='line' id='LC582'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagneticHardSoftIronCompensationParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span><span class="o">*</span> <span class="n">c</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">b</span><span class="p">);</span></div><div class='line' id='LC583'><br/></div><div class='line' id='LC584'><span class="cm">/**</span></div><div class='line' id='LC585'><span class="cm"> * \brief Sets the values of the Magnetic Hard/Soft Iron Compensation Parameters register.</span></div><div class='line' id='LC586'><span class="cm"> *</span></div><div class='line' id='LC587'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC588'><span class="cm"> * \param[in] c The C matrix values to write to the sensor.</span></div><div class='line' id='LC589'><span class="cm"> * \param[in] b The B vector values to write to the sensor.</span></div><div class='line' id='LC590'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC591'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC592'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC593'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC594'><span class="cm"> */</span></div><div class='line' id='LC595'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setMagneticHardSoftIronCompensationParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span> <span class="n">c</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">b</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC596'><br/></div><div class='line' id='LC597'><span class="cm">/**</span></div><div class='line' id='LC598'><span class="cm"> * \brief Gets the values in the Filter Active Tuning Parameters register.</span></div><div class='line' id='LC599'><span class="cm"> *</span></div><div class='line' id='LC600'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC601'><span class="cm"> * \param[out] magneticGain The magnetic disturbance gain value of the sensor.</span></div><div class='line' id='LC602'><span class="cm"> * \param[out] accelerationGain The acceleration disturbance gain value of the sensor.</span></div><div class='line' id='LC603'><span class="cm"> * \param[out] magneticMemory The magnetic disturbance memory value of the sensor.</span></div><div class='line' id='LC604'><span class="cm"> * \param[out] accelerationMemory The acceleration disturbance memory value of the sensor.</span></div><div class='line' id='LC605'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC606'><span class="cm"> */</span></div><div class='line' id='LC607'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getFilterActiveTuningParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">magneticGain</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">accelerationGain</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">magneticMemory</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">accelerationMemory</span><span class="p">);</span></div><div class='line' id='LC608'><br/></div><div class='line' id='LC609'><span class="cm">/**</span></div><div class='line' id='LC610'><span class="cm"> * \brief Sets the values of the Filter Active Tuning Parameters register.</span></div><div class='line' id='LC611'><span class="cm"> *</span></div><div class='line' id='LC612'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC613'><span class="cm"> * \param[in] magneticGain Value for the magnetic disturbance gain field.</span></div><div class='line' id='LC614'><span class="cm"> * \param[in] accelerationGain Value for the acceleration disturbance gain field.</span></div><div class='line' id='LC615'><span class="cm"> * \param[in] magneticMemory Value for the magnetic disturbance memory field.</span></div><div class='line' id='LC616'><span class="cm"> * \param[in] accelerationMemory Value for the acceleration disturbance memory field.</span></div><div class='line' id='LC617'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC618'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC619'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC620'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC621'><span class="cm"> */</span></div><div class='line' id='LC622'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setFilterActiveTuningParameters</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span> <span class="n">magneticGain</span><span class="p">,</span> <span class="kt">double</span> <span class="n">accelerationGain</span><span class="p">,</span> <span class="kt">double</span> <span class="n">magneticMemory</span><span class="p">,</span> <span class="kt">double</span> <span class="n">accelerationMemory</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC623'><br/></div><div class='line' id='LC624'><span class="cm">/**</span></div><div class='line' id='LC625'><span class="cm"> * \brief Gets the values in the Accelerometer Compensation register.</span></div><div class='line' id='LC626'><span class="cm"> *</span></div><div class='line' id='LC627'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC628'><span class="cm"> * \param[out] c The current sensor C matrix values.</span></div><div class='line' id='LC629'><span class="cm"> * \param[out] b The current sensor B vector values.</span></div><div class='line' id='LC630'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC631'><span class="cm"> */</span></div><div class='line' id='LC632'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAccelerometerCompensation</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span><span class="o">*</span> <span class="n">c</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">b</span><span class="p">);</span></div><div class='line' id='LC633'><br/></div><div class='line' id='LC634'><span class="cm">/**</span></div><div class='line' id='LC635'><span class="cm"> * \brief Sets the values of the Accelerometer Compensation register.</span></div><div class='line' id='LC636'><span class="cm"> *</span></div><div class='line' id='LC637'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC638'><span class="cm"> * \param[in] c The C matrix values to write to the sensor.</span></div><div class='line' id='LC639'><span class="cm"> * \param[in] b The B vector values to write to the sensor.</span></div><div class='line' id='LC640'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC641'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC642'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC643'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC644'><span class="cm"> */</span></div><div class='line' id='LC645'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setAccelerometerCompensation</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span> <span class="n">c</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">b</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC646'><br/></div><div class='line' id='LC647'><span class="cm">/**</span></div><div class='line' id='LC648'><span class="cm"> * \brief Gets the values in the Reference Frame Rotation register.</span></div><div class='line' id='LC649'><span class="cm"> *</span></div><div class='line' id='LC650'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC651'><span class="cm"> * \param[out] c The current sensor C matrix values.</span></div><div class='line' id='LC652'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC653'><span class="cm"> */</span></div><div class='line' id='LC654'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getReferenceFrameRotation</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span><span class="o">*</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC655'><br/></div><div class='line' id='LC656'><span class="cm">/**</span></div><div class='line' id='LC657'><span class="cm"> * \brief Sets the values of the Reference Frame Rotation register.</span></div><div class='line' id='LC658'><span class="cm"> *</span></div><div class='line' id='LC659'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC660'><span class="cm"> * \param[in] c The C matrix values to write to the sensor.</span></div><div class='line' id='LC661'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC662'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC663'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC664'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC665'><span class="cm"> */</span></div><div class='line' id='LC666'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setReferenceFrameRotation</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span> <span class="n">c</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC667'><br/></div><div class='line' id='LC668'><span class="cm">/**</span></div><div class='line' id='LC669'><span class="cm"> * \brief Gets the values in the Yaw,Pitch,Roll, Magnetic, Acceleration and Angular Rates register.</span></div><div class='line' id='LC670'><span class="cm"> *</span></div><div class='line' id='LC671'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC672'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC673'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC674'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC675'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC676'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC677'><span class="cm"> */</span></div><div class='line' id='LC678'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRollMagneticAccelerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC679'><br/></div><div class='line' id='LC680'><span class="cm">/**</span></div><div class='line' id='LC681'><span class="cm"> * \brief Gets the values in the Accelerometer Gain register.</span></div><div class='line' id='LC682'><span class="cm"> *</span></div><div class='line' id='LC683'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC684'><span class="cm"> * \param[out] accelerometerGain The accelerometer gain mode value of the sensor.</span></div><div class='line' id='LC685'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC686'><span class="cm"> */</span></div><div class='line' id='LC687'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAccelerometerGain</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">accelerometerGain</span><span class="p">);</span></div><div class='line' id='LC688'><br/></div><div class='line' id='LC689'><span class="cm">/**</span></div><div class='line' id='LC690'><span class="cm"> * \brief Sets the values of the Accelerometer Gain register.</span></div><div class='line' id='LC691'><span class="cm"> *</span></div><div class='line' id='LC692'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC693'><span class="cm"> * \param[in] accelerometerGain Value for the accelerometer gain mode field.</span></div><div class='line' id='LC694'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC695'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC696'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC697'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC698'><span class="cm"> */</span></div><div class='line' id='LC699'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setAccelerometerGain</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">accelerometerGain</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC700'><br/></div><div class='line' id='LC701'><span class="cm">/**</span></div><div class='line' id='LC702'><span class="cm"> * \brief Gets the values in the Yaw,Pitch,Roll, and Calibrated Measurements register.</span></div><div class='line' id='LC703'><span class="cm"> *</span></div><div class='line' id='LC704'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC705'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC706'><span class="cm"> * \param[out] magnetic The current sensor magnetic (X,Y,Z) values.</span></div><div class='line' id='LC707'><span class="cm"> * \param[out] acceleration The current sensor acceleration (X,Y,Z) values.</span></div><div class='line' id='LC708'><span class="cm"> * \param[out] angularRate The current sensor uncompensated angular rate (X,Y,Z) values.</span></div><div class='line' id='LC709'><span class="cm"> * \param[out] temperature The temperature value of the sensor.</span></div><div class='line' id='LC710'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC711'><span class="cm"> */</span></div><div class='line' id='LC712'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRollAndCalibratedMeasurements</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">temperature</span><span class="p">);</span></div><div class='line' id='LC713'><br/></div><div class='line' id='LC714'><span class="cm">/**</span></div><div class='line' id='LC715'><span class="cm"> * \brief Gets the values in the Communication Protocol Control register.</span></div><div class='line' id='LC716'><span class="cm"> *</span></div><div class='line' id='LC717'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC718'><span class="cm"> * \param[out] serialCount The serial count value of the sensor.</span></div><div class='line' id='LC719'><span class="cm"> * \param[out] serialStatus The serial status value of the sensor.</span></div><div class='line' id='LC720'><span class="cm"> * \param[out] spiCount The SPI count value of the sensor.</span></div><div class='line' id='LC721'><span class="cm"> * \param[out] spiStatus The SPI status value of the sensor.</span></div><div class='line' id='LC722'><span class="cm"> * \param[out] serialChecksum The serial checksum value of the sensor.</span></div><div class='line' id='LC723'><span class="cm"> * \param[out] spiChecksum The SPI checksum value of the sensor.</span></div><div class='line' id='LC724'><span class="cm"> * \param[out] errorMode The error mode value of the sensor.</span></div><div class='line' id='LC725'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC726'><span class="cm"> */</span></div><div class='line' id='LC727'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getCommunicationProtocolControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">serialCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">serialStatus</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">spiCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">spiStatus</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">serialChecksum</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">spiChecksum</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">errorMode</span><span class="p">);</span></div><div class='line' id='LC728'><br/></div><div class='line' id='LC729'><span class="cm">/**</span></div><div class='line' id='LC730'><span class="cm"> * \brief Sets the values of the Communication Protocol Control register.</span></div><div class='line' id='LC731'><span class="cm"> *</span></div><div class='line' id='LC732'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC733'><span class="cm"> * \param[in] serialCount Value for the serial count field.</span></div><div class='line' id='LC734'><span class="cm"> * \param[in] serialStatus Value for the serial status field.</span></div><div class='line' id='LC735'><span class="cm"> * \param[in] spiCount Value for the SPI count field.</span></div><div class='line' id='LC736'><span class="cm"> * \param[in] spiStatus Value for the SPI status field.</span></div><div class='line' id='LC737'><span class="cm"> * \param[in] serialChecksum Value for the serial checksum field.</span></div><div class='line' id='LC738'><span class="cm"> * \param[in] spiChecksum Value for the SPI checksum field.</span></div><div class='line' id='LC739'><span class="cm"> * \param[in] errorMode Value for the error mode field.</span></div><div class='line' id='LC740'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC741'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC742'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC743'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC744'><span class="cm"> */</span></div><div class='line' id='LC745'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setCommunicationProtocolControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">serialCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">serialStatus</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">spiCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">spiStatus</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">serialChecksum</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">spiChecksum</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">errorMode</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC746'><br/></div><div class='line' id='LC747'><span class="cm">/**</span></div><div class='line' id='LC748'><span class="cm"> * \brief Gets the values in the Communication Protocol Status register.</span></div><div class='line' id='LC749'><span class="cm"> *</span></div><div class='line' id='LC750'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC751'><span class="cm"> * \param[out] numOfParsedSerialMessages The number of successfully parsed serial messages received value of the sensor.</span></div><div class='line' id='LC752'><span class="cm"> * \param[out] numOfParsedSpiMessages The number of successfully parsed SPI messages received value of the sensor.</span></div><div class='line' id='LC753'><span class="cm"> * \param[out] maxUsageSerialRxBuffer The maximum percent usage of serial incoming buffer value of the sensor.</span></div><div class='line' id='LC754'><span class="cm"> * \param[out] maxUsageSerialTxBuffer The maximum percent usage of serial outgoing buffer value of the sensor.</span></div><div class='line' id='LC755'><span class="cm"> * \param[out] maxUsageSpiRxBuffer The maximum percent usage of SPI incoming buffer value of the sensor.</span></div><div class='line' id='LC756'><span class="cm"> * \param[out] maxUsageSpiTxBuffer The maximum percent usage of SPI outgoing buffer value of the sensor.</span></div><div class='line' id='LC757'><span class="cm"> * \param[out] reserved0 The reserved 0 value of the sensor.</span></div><div class='line' id='LC758'><span class="cm"> * \param[out] reserved1 The reserved 1 value of the sensor.</span></div><div class='line' id='LC759'><span class="cm"> * \param[out] reserved2 The reserved 2 value of the sensor.</span></div><div class='line' id='LC760'><span class="cm"> * \param[out] reserved3 The reserved 3 value of the sensor.</span></div><div class='line' id='LC761'><span class="cm"> * \param[out] reserved4 The reserved 4 value of the sensor.</span></div><div class='line' id='LC762'><span class="cm"> * \param[out] reserved5 The reserved 5 value of the sensor.</span></div><div class='line' id='LC763'><span class="cm"> * \param[out] reserved6 The reserved 6 value of the sensor.</span></div><div class='line' id='LC764'><span class="cm"> * \param[out] reserved7 The reserved 7 value of the sensor.</span></div><div class='line' id='LC765'><span class="cm"> * \param[out] reserved8 The reserved 8 value of the sensor.</span></div><div class='line' id='LC766'><span class="cm"> * \param[out] reserved9 The reserved 9 value of the sensor.</span></div><div class='line' id='LC767'><span class="cm"> * \param[out] reserved10 The reserved 10 value of the sensor.</span></div><div class='line' id='LC768'><span class="cm"> * \param[out] reserved11 The reserved 11 value of the sensor.</span></div><div class='line' id='LC769'><span class="cm"> * \param[out] reserved12 The reserved 12 value of the sensor.</span></div><div class='line' id='LC770'><span class="cm"> * \param[out] reserved13 The reserved 13 value of the sensor.</span></div><div class='line' id='LC771'><span class="cm"> * \param[out] reserved14 The reserved 14 value of the sensor.</span></div><div class='line' id='LC772'><span class="cm"> * \param[out] reserved15 The reserved 15 value of the sensor.</span></div><div class='line' id='LC773'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC774'><span class="cm"> */</span></div><div class='line' id='LC775'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getCommunicationProtocolStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">numOfParsedSerialMessages</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">numOfParsedSpiMessages</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">maxUsageSerialRxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">maxUsageSerialTxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">maxUsageSpiRxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">maxUsageSpiTxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved0</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved1</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved2</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved3</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved4</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved5</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved6</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved7</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved8</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved9</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved10</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved11</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved12</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved13</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved14</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">reserved15</span><span class="p">);</span></div><div class='line' id='LC776'><br/></div><div class='line' id='LC777'><span class="cm">/**</span></div><div class='line' id='LC778'><span class="cm"> * \brief Sets the values of the Communication Protocol Status register.</span></div><div class='line' id='LC779'><span class="cm"> *</span></div><div class='line' id='LC780'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC781'><span class="cm"> * \param[in] numOfParsedSerialMessages Value for the number of successfully parsed serial messages received field.</span></div><div class='line' id='LC782'><span class="cm"> * \param[in] numOfParsedSpiMessages Value for the number of successfully parsed SPI messages received field.</span></div><div class='line' id='LC783'><span class="cm"> * \param[in] maxUsageSerialRxBuffer Value for the maximum percent usage of serial incoming buffer field.</span></div><div class='line' id='LC784'><span class="cm"> * \param[in] maxUsageSerialTxBuffer Value for the maximum percent usage of serial outgoing buffer field.</span></div><div class='line' id='LC785'><span class="cm"> * \param[in] maxUsageSpiRxBuffer Value for the maximum percent usage of SPI incoming buffer field.</span></div><div class='line' id='LC786'><span class="cm"> * \param[in] maxUsageSpiTxBuffer Value for the maximum percent usage of SPI outgoing buffer field.</span></div><div class='line' id='LC787'><span class="cm"> * \param[in] reserved0 Value for the reserved 0 field.</span></div><div class='line' id='LC788'><span class="cm"> * \param[in] reserved1 Value for the reserved 1 field.</span></div><div class='line' id='LC789'><span class="cm"> * \param[in] reserved2 Value for the reserved 2 field.</span></div><div class='line' id='LC790'><span class="cm"> * \param[in] reserved3 Value for the reserved 3 field.</span></div><div class='line' id='LC791'><span class="cm"> * \param[in] reserved4 Value for the reserved 4 field.</span></div><div class='line' id='LC792'><span class="cm"> * \param[in] reserved5 Value for the reserved 5 field.</span></div><div class='line' id='LC793'><span class="cm"> * \param[in] reserved6 Value for the reserved 6 field.</span></div><div class='line' id='LC794'><span class="cm"> * \param[in] reserved7 Value for the reserved 7 field.</span></div><div class='line' id='LC795'><span class="cm"> * \param[in] reserved8 Value for the reserved 8 field.</span></div><div class='line' id='LC796'><span class="cm"> * \param[in] reserved9 Value for the reserved 9 field.</span></div><div class='line' id='LC797'><span class="cm"> * \param[in] reserved10 Value for the reserved 10 field.</span></div><div class='line' id='LC798'><span class="cm"> * \param[in] reserved11 Value for the reserved 11 field.</span></div><div class='line' id='LC799'><span class="cm"> * \param[in] reserved12 Value for the reserved 12 field.</span></div><div class='line' id='LC800'><span class="cm"> * \param[in] reserved13 Value for the reserved 13 field.</span></div><div class='line' id='LC801'><span class="cm"> * \param[in] reserved14 Value for the reserved 14 field.</span></div><div class='line' id='LC802'><span class="cm"> * \param[in] reserved15 Value for the reserved 15 field.</span></div><div class='line' id='LC803'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC804'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC805'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC806'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC807'><span class="cm"> */</span></div><div class='line' id='LC808'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setCommunicationProtocolStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfParsedSerialMessages</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfParsedSpiMessages</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">maxUsageSerialRxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">maxUsageSerialTxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">maxUsageSpiRxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">maxUsageSpiTxBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved0</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved1</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved2</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved3</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved4</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved5</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved6</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved7</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved8</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved9</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved10</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved11</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved12</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved13</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved14</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">reserved15</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC809'><br/></div><div class='line' id='LC810'><span class="cm">/**</span></div><div class='line' id='LC811'><span class="cm"> * \brief Gets the values in the Synchronization Control register.</span></div><div class='line' id='LC812'><span class="cm"> *</span></div><div class='line' id='LC813'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC814'><span class="cm"> * \param[out] syncInMode The input signal synchronization mode value of the sensor.</span></div><div class='line' id='LC815'><span class="cm"> * \param[out] syncInEdge The input signal synchronization edge selection value of the sensor.</span></div><div class='line' id='LC816'><span class="cm"> * \param[out] syncInSkipFactor The input signal trigger skip factor value of the sensor.</span></div><div class='line' id='LC817'><span class="cm"> * \param[out] reserved0 The reserved value of the sensor.</span></div><div class='line' id='LC818'><span class="cm"> * \param[out] syncOutMode The output signal synchronization mode value of the sensor.</span></div><div class='line' id='LC819'><span class="cm"> * \param[out] syncOutPolarity The output signal synchronization polarity value of the sensor.</span></div><div class='line' id='LC820'><span class="cm"> * \param[out] syncOutSkipFactor The output synchronization signal skip factor value of the sensor.</span></div><div class='line' id='LC821'><span class="cm"> * \param[out] syncOutPulseWidth The output synchronization signal pulse width value of the sensor.</span></div><div class='line' id='LC822'><span class="cm"> * \param[out] reserved1 The reserved value of the sensor.</span></div><div class='line' id='LC823'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC824'><span class="cm"> */</span></div><div class='line' id='LC825'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getSynchronizationControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">syncInMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">syncInEdge</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">syncInSkipFactor</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">reserved0</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">syncOutMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">syncOutPolarity</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">syncOutSkipFactor</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">syncOutPulseWidth</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">reserved1</span><span class="p">);</span></div><div class='line' id='LC826'><br/></div><div class='line' id='LC827'><span class="cm">/**</span></div><div class='line' id='LC828'><span class="cm"> * \brief Sets the values of the Synchronization Control register.</span></div><div class='line' id='LC829'><span class="cm"> *</span></div><div class='line' id='LC830'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC831'><span class="cm"> * \param[in] syncInMode Value for the input signal synchronization mode field.</span></div><div class='line' id='LC832'><span class="cm"> * \param[in] syncInEdge Value for the input signal synchronization edge selection field.</span></div><div class='line' id='LC833'><span class="cm"> * \param[in] syncInSkipFactor Value for the input signal trigger skip factor field.</span></div><div class='line' id='LC834'><span class="cm"> * \param[in] reserved0 Value for the reserved field.</span></div><div class='line' id='LC835'><span class="cm"> * \param[in] syncOutMode Value for the output signal synchronization mode field.</span></div><div class='line' id='LC836'><span class="cm"> * \param[in] syncOutPolarity Value for the output signal synchronization polarity field.</span></div><div class='line' id='LC837'><span class="cm"> * \param[in] syncOutSkipFactor Value for the output synchronization signal skip factor field.</span></div><div class='line' id='LC838'><span class="cm"> * \param[in] syncOutPulseWidth Value for the output synchronization signal pulse width field.</span></div><div class='line' id='LC839'><span class="cm"> * \param[in] reserved1 Value for the reserved field.</span></div><div class='line' id='LC840'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC841'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC842'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC843'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC844'><span class="cm"> */</span></div><div class='line' id='LC845'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setSynchronizationControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">syncInMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">syncInEdge</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">syncInSkipFactor</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">reserved0</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">syncOutMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">syncOutPolarity</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span> <span class="n">syncOutSkipFactor</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">syncOutPulseWidth</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">reserved1</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC846'><br/></div><div class='line' id='LC847'><span class="cm">/**</span></div><div class='line' id='LC848'><span class="cm"> * \brief Gets the values in the Synchronization Status register.</span></div><div class='line' id='LC849'><span class="cm"> *</span></div><div class='line' id='LC850'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC851'><span class="cm"> * \param[out] syncInCount The synchronization in count value of the sensor.</span></div><div class='line' id='LC852'><span class="cm"> * \param[out] syncInTime The synchronization in time value of the sensor.</span></div><div class='line' id='LC853'><span class="cm"> * \param[out] syncOutCount The synchronization out count value of the sensor.</span></div><div class='line' id='LC854'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC855'><span class="cm"> */</span></div><div class='line' id='LC856'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getSynchronizationStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">syncInCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">syncInTime</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">syncOutCount</span><span class="p">);</span></div><div class='line' id='LC857'><br/></div><div class='line' id='LC858'><span class="cm">/**</span></div><div class='line' id='LC859'><span class="cm"> * \brief Sets the values of the Synchronization Status register.</span></div><div class='line' id='LC860'><span class="cm"> *</span></div><div class='line' id='LC861'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC862'><span class="cm"> * \param[in] syncInCount Value for the synchronization in count field.</span></div><div class='line' id='LC863'><span class="cm"> * \param[in] syncInTime Value for the synchronization in time field.</span></div><div class='line' id='LC864'><span class="cm"> * \param[in] syncOutCount Value for the synchronization out count field.</span></div><div class='line' id='LC865'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC866'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC867'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC868'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC869'><span class="cm"> */</span></div><div class='line' id='LC870'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setSynchronizationStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">syncInCount</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">syncInTime</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">syncOutCount</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC871'><br/></div><div class='line' id='LC872'><span class="cm">/**</span></div><div class='line' id='LC873'><span class="cm"> * \brief Gets the values in the Attitude Filter Control register.</span></div><div class='line' id='LC874'><span class="cm"> *</span></div><div class='line' id='LC875'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC876'><span class="cm"> * \param[out] magneticMode The magnetic mode value of the sensor.</span></div><div class='line' id='LC877'><span class="cm"> * \param[out] externalMagnetometerMode The external magnetometer mode value of the sensor.</span></div><div class='line' id='LC878'><span class="cm"> * \param[out] externalAccelerometerMode The external accelerometer mode value of the sensor.</span></div><div class='line' id='LC879'><span class="cm"> * \param[out] externalGyroscopeMode The external gyroscope mode value of the sensor.</span></div><div class='line' id='LC880'><span class="cm"> * \param[out] angularRateLimit The current sensor angular rate saturation liimit (X,Y,Z) values.</span></div><div class='line' id='LC881'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC882'><span class="cm"> */</span></div><div class='line' id='LC883'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getAttitudeFilterControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">magneticMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">externalMagnetometerMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">externalAccelerometerMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">externalGyroscopeMode</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRateLimit</span><span class="p">);</span></div><div class='line' id='LC884'><br/></div><div class='line' id='LC885'><span class="cm">/**</span></div><div class='line' id='LC886'><span class="cm"> * \brief Sets the values of the Attitude Filter Control register.</span></div><div class='line' id='LC887'><span class="cm"> *</span></div><div class='line' id='LC888'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC889'><span class="cm"> * \param[in] magneticMode Value for the magnetic mode field.</span></div><div class='line' id='LC890'><span class="cm"> * \param[in] externalMagnetometerMode Value for the external magnetometer mode field.</span></div><div class='line' id='LC891'><span class="cm"> * \param[in] externalAccelerometerMode Value for the external accelerometer mode field.</span></div><div class='line' id='LC892'><span class="cm"> * \param[in] externalGyroscopeMode Value for the external gyroscope mode field.</span></div><div class='line' id='LC893'><span class="cm"> * \param[in] angularRateLimit The angular rate saturation liimit (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC894'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC895'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC896'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC897'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC898'><span class="cm"> */</span></div><div class='line' id='LC899'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setAttitudeFilterControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">magneticMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">externalMagnetometerMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">externalAccelerometerMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">externalGyroscopeMode</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">angularRateLimit</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC900'><br/></div><div class='line' id='LC901'><span class="cm">/**</span></div><div class='line' id='LC902'><span class="cm"> * \brief Gets the values in the VPE Control register.</span></div><div class='line' id='LC903'><span class="cm"> *</span></div><div class='line' id='LC904'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC905'><span class="cm"> * \param[out] enable The enable/disable value of the sensor.</span></div><div class='line' id='LC906'><span class="cm"> * \param[out] headingMode The heading mode value of the sensor.</span></div><div class='line' id='LC907'><span class="cm"> * \param[out] filteringMode The filtering mode value of the sensor.</span></div><div class='line' id='LC908'><span class="cm"> * \param[out] tuningMode The tuning mode value of the sensor.</span></div><div class='line' id='LC909'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC910'><span class="cm"> */</span></div><div class='line' id='LC911'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">enable</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">headingMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">filteringMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">tuningMode</span><span class="p">);</span></div><div class='line' id='LC912'><br/></div><div class='line' id='LC913'><span class="cm">/**</span></div><div class='line' id='LC914'><span class="cm"> * \brief Sets the values of the VPE Control register.</span></div><div class='line' id='LC915'><span class="cm"> *</span></div><div class='line' id='LC916'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC917'><span class="cm"> * \param[in] enable Value for the enable/disable field.</span></div><div class='line' id='LC918'><span class="cm"> * \param[in] headingMode Value for the heading mode field.</span></div><div class='line' id='LC919'><span class="cm"> * \param[in] filteringMode Value for the filtering mode field.</span></div><div class='line' id='LC920'><span class="cm"> * \param[in] tuningMode Value for the tuning mode field.</span></div><div class='line' id='LC921'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC922'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC923'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC924'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC925'><span class="cm"> */</span></div><div class='line' id='LC926'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">enable</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">headingMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">filteringMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">tuningMode</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC927'><br/></div><div class='line' id='LC928'><span class="cm">/**</span></div><div class='line' id='LC929'><span class="cm"> * \brief Gets the values in the VPE Magnetometer Basic Tuning register.</span></div><div class='line' id='LC930'><span class="cm"> *</span></div><div class='line' id='LC931'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC932'><span class="cm"> * \param[out] baseTuning The current sensor magnetometer base tuning (X,Y,Z) values.</span></div><div class='line' id='LC933'><span class="cm"> * \param[out] adaptiveTuning The current sensor magnetometer adaptive tuning (X,Y,Z) values.</span></div><div class='line' id='LC934'><span class="cm"> * \param[out] adaptiveFiltering The current sensor magnetometer adaptive filtering (X,Y,Z) values.</span></div><div class='line' id='LC935'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC936'><span class="cm"> */</span></div><div class='line' id='LC937'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeMagnetometerBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveFiltering</span><span class="p">);</span></div><div class='line' id='LC938'><br/></div><div class='line' id='LC939'><span class="cm">/**</span></div><div class='line' id='LC940'><span class="cm"> * \brief Sets the values of the VPE Magnetometer Basic Tuning register.</span></div><div class='line' id='LC941'><span class="cm"> *</span></div><div class='line' id='LC942'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC943'><span class="cm"> * \param[in] baseTuning The magnetometer base tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC944'><span class="cm"> * \param[in] adaptiveTuning The magnetometer adaptive tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC945'><span class="cm"> * \param[in] adaptiveFiltering The magnetometer adaptive filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC946'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC947'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC948'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC949'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC950'><span class="cm"> */</span></div><div class='line' id='LC951'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeMagnetometerBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveFiltering</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC952'><br/></div><div class='line' id='LC953'><span class="cm">/**</span></div><div class='line' id='LC954'><span class="cm"> * \brief Gets the values in the VPE Magnetometer Advanced Tuning register.</span></div><div class='line' id='LC955'><span class="cm"> *</span></div><div class='line' id='LC956'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC957'><span class="cm"> * \param[out] minimumFiltering The current sensor minimum allowed level of filtering (X,Y,Z) values.</span></div><div class='line' id='LC958'><span class="cm"> * \param[out] maximumFiltering The current sensor maximum allowed level of filtering (X,Y,Z) values.</span></div><div class='line' id='LC959'><span class="cm"> * \param[out] maximumAdaptRate The MaxAdaptRate value of the sensor.</span></div><div class='line' id='LC960'><span class="cm"> * \param[out] disturbanceWindow The DisturbanceWindow value of the sensor.</span></div><div class='line' id='LC961'><span class="cm"> * \param[out] maximumTuning The MaxTuning value of the sensor.</span></div><div class='line' id='LC962'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC963'><span class="cm"> */</span></div><div class='line' id='LC964'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeMagnetometerAdvancedTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">minimumFiltering</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">maximumFiltering</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">maximumAdaptRate</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">disturbanceWindow</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">maximumTuning</span><span class="p">);</span></div><div class='line' id='LC965'><br/></div><div class='line' id='LC966'><span class="cm">/**</span></div><div class='line' id='LC967'><span class="cm"> * \brief Sets the values of the VPE Magnetometer Advanced Tuning register.</span></div><div class='line' id='LC968'><span class="cm"> *</span></div><div class='line' id='LC969'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC970'><span class="cm"> * \param[in] minimumFiltering The minimum allowed level of filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC971'><span class="cm"> * \param[in] maximumFiltering The maximum allowed level of filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC972'><span class="cm"> * \param[in] maximumAdaptRate Value for the MaxAdaptRate field.</span></div><div class='line' id='LC973'><span class="cm"> * \param[in] disturbanceWindow Value for the DisturbanceWindow field.</span></div><div class='line' id='LC974'><span class="cm"> * \param[in] maximumTuning Value for the MaxTuning field.</span></div><div class='line' id='LC975'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC976'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC977'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC978'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC979'><span class="cm"> */</span></div><div class='line' id='LC980'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeMagnetometerAdvancedTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">minimumFiltering</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">maximumFiltering</span><span class="p">,</span> <span class="kt">double</span> <span class="n">maximumAdaptRate</span><span class="p">,</span> <span class="kt">double</span> <span class="n">disturbanceWindow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">maximumTuning</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC981'><br/></div><div class='line' id='LC982'><span class="cm">/**</span></div><div class='line' id='LC983'><span class="cm"> * \brief Gets the values in the VPE Accelerometer Basic Tuning register.</span></div><div class='line' id='LC984'><span class="cm"> *</span></div><div class='line' id='LC985'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC986'><span class="cm"> * \param[out] baseTuning The current sensor accelerometer base tuning (X,Y,Z) values.</span></div><div class='line' id='LC987'><span class="cm"> * \param[out] adaptiveTuning The current sensor accelerometer adaptive tuning (X,Y,Z) values.</span></div><div class='line' id='LC988'><span class="cm"> * \param[out] adaptiveFiltering The current sensor accelerometer adaptive filtering (X,Y,Z) values.</span></div><div class='line' id='LC989'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC990'><span class="cm"> */</span></div><div class='line' id='LC991'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeAccelerometerBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveFiltering</span><span class="p">);</span></div><div class='line' id='LC992'><br/></div><div class='line' id='LC993'><span class="cm">/**</span></div><div class='line' id='LC994'><span class="cm"> * \brief Sets the values of the VPE Accelerometer Basic Tuning register.</span></div><div class='line' id='LC995'><span class="cm"> *</span></div><div class='line' id='LC996'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC997'><span class="cm"> * \param[in] baseTuning The accelerometer base tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC998'><span class="cm"> * \param[in] adaptiveTuning The accelerometer adaptive tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC999'><span class="cm"> * \param[in] adaptiveFiltering The accelerometer adaptive filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1000'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1001'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1002'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1003'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1004'><span class="cm"> */</span></div><div class='line' id='LC1005'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeAccelerometerBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveFiltering</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1006'><br/></div><div class='line' id='LC1007'><span class="cm">/**</span></div><div class='line' id='LC1008'><span class="cm"> * \brief Gets the values in the VPE Accelerometer Advanced Tuning register.</span></div><div class='line' id='LC1009'><span class="cm"> *</span></div><div class='line' id='LC1010'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1011'><span class="cm"> * \param[out] minimumFiltering The current sensor minimum allowed level of filtering (X,Y,Z) values.</span></div><div class='line' id='LC1012'><span class="cm"> * \param[out] maximumFiltering The current sensor maximum allowed level of filtering (X,Y,Z) values.</span></div><div class='line' id='LC1013'><span class="cm"> * \param[out] maximumAdaptRate The MaxAdaptRate value of the sensor.</span></div><div class='line' id='LC1014'><span class="cm"> * \param[out] disturbanceWindow The DisturbanceWindow value of the sensor.</span></div><div class='line' id='LC1015'><span class="cm"> * \param[out] maximumTuning The MaxTuning value of the sensor.</span></div><div class='line' id='LC1016'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1017'><span class="cm"> */</span></div><div class='line' id='LC1018'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeAccelerometerAdvancedTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">minimumFiltering</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">maximumFiltering</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">maximumAdaptRate</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">disturbanceWindow</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">maximumTuning</span><span class="p">);</span></div><div class='line' id='LC1019'><br/></div><div class='line' id='LC1020'><span class="cm">/**</span></div><div class='line' id='LC1021'><span class="cm"> * \brief Sets the values of the VPE Accelerometer Advanced Tuning register.</span></div><div class='line' id='LC1022'><span class="cm"> *</span></div><div class='line' id='LC1023'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1024'><span class="cm"> * \param[in] minimumFiltering The minimum allowed level of filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1025'><span class="cm"> * \param[in] maximumFiltering The maximum allowed level of filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1026'><span class="cm"> * \param[in] maximumAdaptRate Value for the MaxAdaptRate field.</span></div><div class='line' id='LC1027'><span class="cm"> * \param[in] disturbanceWindow Value for the DisturbanceWindow field.</span></div><div class='line' id='LC1028'><span class="cm"> * \param[in] maximumTuning Value for the MaxTuning field.</span></div><div class='line' id='LC1029'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1030'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1031'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1032'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1033'><span class="cm"> */</span></div><div class='line' id='LC1034'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeAccelerometerAdvancedTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">minimumFiltering</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">maximumFiltering</span><span class="p">,</span> <span class="kt">double</span> <span class="n">maximumAdaptRate</span><span class="p">,</span> <span class="kt">double</span> <span class="n">disturbanceWindow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">maximumTuning</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1035'><br/></div><div class='line' id='LC1036'><span class="cm">/**</span></div><div class='line' id='LC1037'><span class="cm"> * \brief Gets the values in the VPE Gyro Basic Tuning register.</span></div><div class='line' id='LC1038'><span class="cm"> *</span></div><div class='line' id='LC1039'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1040'><span class="cm"> * \param[out] baseTuning The current sensor gyroscope base tuning (X,Y,Z) values.</span></div><div class='line' id='LC1041'><span class="cm"> * \param[out] adaptiveTuning The current sensor gyroscope adaptive tuning (X,Y,Z) values.</span></div><div class='line' id='LC1042'><span class="cm"> * \param[out] adaptiveFiltering The current sensor gyroscope adaptive filtering (X,Y,Z) values.</span></div><div class='line' id='LC1043'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1044'><span class="cm"> */</span></div><div class='line' id='LC1045'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getVpeGyroBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">adaptiveFiltering</span><span class="p">);</span></div><div class='line' id='LC1046'><br/></div><div class='line' id='LC1047'><span class="cm">/**</span></div><div class='line' id='LC1048'><span class="cm"> * \brief Sets the values of the VPE Gyro Basic Tuning register.</span></div><div class='line' id='LC1049'><span class="cm"> *</span></div><div class='line' id='LC1050'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1051'><span class="cm"> * \param[in] baseTuning The gyroscope base tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1052'><span class="cm"> * \param[in] adaptiveTuning The gyroscope adaptive tuning (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1053'><span class="cm"> * \param[in] adaptiveFiltering The gyroscope adaptive filtering (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1054'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1055'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1056'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1057'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1058'><span class="cm"> */</span></div><div class='line' id='LC1059'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setVpeGyroBasicTuning</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">baseTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveTuning</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">adaptiveFiltering</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1060'><br/></div><div class='line' id='LC1061'><span class="cm">/**</span></div><div class='line' id='LC1062'><span class="cm"> * \brief Gets the values in the Filter Status register.</span></div><div class='line' id='LC1063'><span class="cm"> *</span></div><div class='line' id='LC1064'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1065'><span class="cm"> * \param[out] solutionStatus The solution status bitfield value of the sensor.</span></div><div class='line' id='LC1066'><span class="cm"> * \param[out] yawUncertainty The YawUncertainty value of the sensor.</span></div><div class='line' id='LC1067'><span class="cm"> * \param[out] pitchUncertainty The PitchUncertainty value of the sensor.</span></div><div class='line' id='LC1068'><span class="cm"> * \param[out] rollUncertainty The RollUncertainty value of the sensor.</span></div><div class='line' id='LC1069'><span class="cm"> * \param[out] gyroBiasUncertainty The GyroBiasUncertainty value of the sensor.</span></div><div class='line' id='LC1070'><span class="cm"> * \param[out] magUncertainty The MagUncertainty value of the sensor.</span></div><div class='line' id='LC1071'><span class="cm"> * \param[out] accelUncertainty The AccelUncertainty value of the sensor.</span></div><div class='line' id='LC1072'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1073'><span class="cm"> */</span></div><div class='line' id='LC1074'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getFilterStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">solutionStatus</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">yawUncertainty</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">pitchUncertainty</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">rollUncertainty</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">gyroBiasUncertainty</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">magUncertainty</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">accelUncertainty</span><span class="p">);</span></div><div class='line' id='LC1075'><br/></div><div class='line' id='LC1076'><span class="cm">/**</span></div><div class='line' id='LC1077'><span class="cm"> * \brief Gets the values in the Filter Startup Gyro Bias register.</span></div><div class='line' id='LC1078'><span class="cm"> *</span></div><div class='line' id='LC1079'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1080'><span class="cm"> * \param[out] gyroBias The current sensor gyroscope startup bias (X,Y,Z) values.</span></div><div class='line' id='LC1081'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1082'><span class="cm"> */</span></div><div class='line' id='LC1083'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getFilterStartupGyroBias</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">gyroBias</span><span class="p">);</span></div><div class='line' id='LC1084'><br/></div><div class='line' id='LC1085'><span class="cm">/**</span></div><div class='line' id='LC1086'><span class="cm"> * \brief Sets the values of the Filter Startup Gyro Bias register.</span></div><div class='line' id='LC1087'><span class="cm"> *</span></div><div class='line' id='LC1088'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1089'><span class="cm"> * \param[in] gyroBias The gyroscope startup bias (X,Y,Z) values to write to the sensor.</span></div><div class='line' id='LC1090'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1091'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1092'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1093'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1094'><span class="cm"> */</span></div><div class='line' id='LC1095'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setFilterStartupGyroBias</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span> <span class="n">gyroBias</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1096'><br/></div><div class='line' id='LC1097'><span class="cm">/**</span></div><div class='line' id='LC1098'><span class="cm"> * \brief Gets the values in the Magnetometer Basic Calibration Control register.</span></div><div class='line' id='LC1099'><span class="cm"> *</span></div><div class='line' id='LC1100'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1101'><span class="cm"> * \param[out] hsiMode The HSIMode value of the sensor.</span></div><div class='line' id='LC1102'><span class="cm"> * \param[out] hsiOutput The HSIOutput value of the sensor.</span></div><div class='line' id='LC1103'><span class="cm"> * \param[out] convergeRate The ConvergeRate value of the sensor.</span></div><div class='line' id='LC1104'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1105'><span class="cm"> */</span></div><div class='line' id='LC1106'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagnetometerBasicCalibrationControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">hsiMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">hsiOutput</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">convergeRate</span><span class="p">);</span></div><div class='line' id='LC1107'><br/></div><div class='line' id='LC1108'><span class="cm">/**</span></div><div class='line' id='LC1109'><span class="cm"> * \brief Sets the values of the Magnetometer Basic Calibration Control register.</span></div><div class='line' id='LC1110'><span class="cm"> *</span></div><div class='line' id='LC1111'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1112'><span class="cm"> * \param[in] hsiMode Value for the HSIMode field.</span></div><div class='line' id='LC1113'><span class="cm"> * \param[in] hsiOutput Value for the HSIOutput field.</span></div><div class='line' id='LC1114'><span class="cm"> * \param[in] convergeRate Value for the ConvergeRate field.</span></div><div class='line' id='LC1115'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1116'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1117'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1118'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1119'><span class="cm"> */</span></div><div class='line' id='LC1120'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setMagnetometerBasicCalibrationControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">hsiMode</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">hsiOutput</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span> <span class="n">convergeRate</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1121'><br/></div><div class='line' id='LC1122'><span class="cm">/**</span></div><div class='line' id='LC1123'><span class="cm"> * \brief Gets the values in the Magnetometer Calibration Status register.</span></div><div class='line' id='LC1124'><span class="cm"> *</span></div><div class='line' id='LC1125'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1126'><span class="cm"> * \param[out] lastBin The LastBin value of the sensor.</span></div><div class='line' id='LC1127'><span class="cm"> * \param[out] numOfMeasurements The NumMeas value of the sensor.</span></div><div class='line' id='LC1128'><span class="cm"> * \param[out] avgResidual The AvgResidual value of the sensor.</span></div><div class='line' id='LC1129'><span class="cm"> * \param[out] lastMeasurement The current sensor last measurement (X,Y,Z) values.</span></div><div class='line' id='LC1130'><span class="cm"> * \param[out] bin0 The number of measurements in bin 1 value of the sensor.</span></div><div class='line' id='LC1131'><span class="cm"> * \param[out] bin1 The number of measurements in bin 2 value of the sensor.</span></div><div class='line' id='LC1132'><span class="cm"> * \param[out] bin2 The number of measurements in bin 3 value of the sensor.</span></div><div class='line' id='LC1133'><span class="cm"> * \param[out] bin3 The number of measurements in bin 4 value of the sensor.</span></div><div class='line' id='LC1134'><span class="cm"> * \param[out] bin4 The number of measurements in bin 5 value of the sensor.</span></div><div class='line' id='LC1135'><span class="cm"> * \param[out] bin5 The number of measurements in bin 6 value of the sensor.</span></div><div class='line' id='LC1136'><span class="cm"> * \param[out] bin6 The number of measurements in bin 7 value of the sensor.</span></div><div class='line' id='LC1137'><span class="cm"> * \param[out] bin7 The number of measurements in bin 8 value of the sensor.</span></div><div class='line' id='LC1138'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1139'><span class="cm"> */</span></div><div class='line' id='LC1140'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getMagnetometerCalibrationStatus</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">lastBin</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">short</span><span class="o">*</span> <span class="n">numOfMeasurements</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">avgResidual</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">lastMeasurement</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin0</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin1</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin2</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin3</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin4</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin5</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin6</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">char</span><span class="o">*</span> <span class="n">bin7</span><span class="p">);</span></div><div class='line' id='LC1141'><br/></div><div class='line' id='LC1142'><span class="cm">/**</span></div><div class='line' id='LC1143'><span class="cm"> * \brief Gets the values in the Calculated Magnetometer Calibration register.</span></div><div class='line' id='LC1144'><span class="cm"> *</span></div><div class='line' id='LC1145'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1146'><span class="cm"> * \param[out] c The current sensor C matrix values.</span></div><div class='line' id='LC1147'><span class="cm"> * \param[out] b The current sensor B vector values.</span></div><div class='line' id='LC1148'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1149'><span class="cm"> */</span></div><div class='line' id='LC1150'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getCalculatedMagnetometerCalibration</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnMatrix3x3</span><span class="o">*</span> <span class="n">c</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">b</span><span class="p">);</span></div><div class='line' id='LC1151'><br/></div><div class='line' id='LC1152'><span class="cm">/**</span></div><div class='line' id='LC1153'><span class="cm"> * \brief Gets the values in the Indoor Heading Mode Control register.</span></div><div class='line' id='LC1154'><span class="cm"> *</span></div><div class='line' id='LC1155'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1156'><span class="cm"> * \param[out] maxRateError The MaxRateError value of the sensor.</span></div><div class='line' id='LC1157'><span class="cm"> * \param[out] reserved The reserved value of the sensor.</span></div><div class='line' id='LC1158'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1159'><span class="cm"> */</span></div><div class='line' id='LC1160'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getIndoorHeadingModeControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">maxRateError</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">reserved</span><span class="p">);</span></div><div class='line' id='LC1161'><br/></div><div class='line' id='LC1162'><span class="cm">/**</span></div><div class='line' id='LC1163'><span class="cm"> * \brief Sets the values of the Indoor Heading Mode Control register.</span></div><div class='line' id='LC1164'><span class="cm"> *</span></div><div class='line' id='LC1165'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1166'><span class="cm"> * \param[in] maxRateError Value for the MaxRateError field.</span></div><div class='line' id='LC1167'><span class="cm"> * \param[in] reserved Value for the reserved field.</span></div><div class='line' id='LC1168'><span class="cm"> * \param[in] waitForResponse Signals if the function should block until a response is</span></div><div class='line' id='LC1169'><span class="cm">       received from the sensor. TRUE to block for a response; FALSE to immediately</span></div><div class='line' id='LC1170'><span class="cm">       return after sending out the command.</span></div><div class='line' id='LC1171'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1172'><span class="cm"> */</span></div><div class='line' id='LC1173'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_setIndoorHeadingModeControl</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="kt">double</span> <span class="n">maxRateError</span><span class="p">,</span> <span class="kt">double</span> <span class="n">reserved</span><span class="p">,</span> <span class="n">VN_BOOL</span> <span class="n">waitForResponse</span><span class="p">);</span></div><div class='line' id='LC1174'><br/></div><div class='line' id='LC1175'><span class="cm">/**</span></div><div class='line' id='LC1176'><span class="cm"> * \brief Gets the values in the Yaw,Pitch,Roll, True Body Acceleration and Angular Rates register.</span></div><div class='line' id='LC1177'><span class="cm"> *</span></div><div class='line' id='LC1178'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1179'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC1180'><span class="cm"> * \param[out] bodyAcceleration The current sensor body acceleration (X,Y,Z) values.</span></div><div class='line' id='LC1181'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC1182'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1183'><span class="cm"> */</span></div><div class='line' id='LC1184'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRollTrueBodyAccelerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">bodyAcceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC1185'><br/></div><div class='line' id='LC1186'><span class="cm">/**</span></div><div class='line' id='LC1187'><span class="cm"> * \brief Gets the values in the Yaw,Pitch,Roll, True Inertial Acceleration and Angular Rates register.</span></div><div class='line' id='LC1188'><span class="cm"> *</span></div><div class='line' id='LC1189'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1190'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC1191'><span class="cm"> * \param[out] inertialAcceleration The current sensor inertial acceleration (X,Y,Z) values.</span></div><div class='line' id='LC1192'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC1193'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1194'><span class="cm"> */</span></div><div class='line' id='LC1195'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRollTrueInertialAcclerationAngularRate</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">inertialAcceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC1196'><br/></div><div class='line' id='LC1197'><span class="cm">/**</span></div><div class='line' id='LC1198'><span class="cm"> * \brief Gets the values in the Yaw,Pitch,Roll and Inertial Calibrated Measurements register.</span></div><div class='line' id='LC1199'><span class="cm"> *</span></div><div class='line' id='LC1200'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1201'><span class="cm"> * \param[out] attitude The current sensor YawPitchRoll values.</span></div><div class='line' id='LC1202'><span class="cm"> * \param[out] inertialMagnetic The current sensor inertial magnetic (X,Y,Z) values.</span></div><div class='line' id='LC1203'><span class="cm"> * \param[out] inertialAcceleration The current sensor inertial acceleration (X,Y,Z) values.</span></div><div class='line' id='LC1204'><span class="cm"> * \param[out] angularRate The current sensor angular rate (X,Y,Z) values.</span></div><div class='line' id='LC1205'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1206'><span class="cm"> */</span></div><div class='line' id='LC1207'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getYawPitchRollInertialCalibratedMeasurements</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnYpr</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">inertialMagnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">inertialAcceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">);</span></div><div class='line' id='LC1208'><br/></div><div class='line' id='LC1209'><span class="cm">/**</span></div><div class='line' id='LC1210'><span class="cm"> * \brief Gets the values in the Raw Voltage Measurements register.</span></div><div class='line' id='LC1211'><span class="cm"> *</span></div><div class='line' id='LC1212'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1213'><span class="cm"> * \param[out] magnetometer The current sensor magnetometer raw voltages (X,Y,Z) values.</span></div><div class='line' id='LC1214'><span class="cm"> * \param[out] accelerometer The current sensor accelerometer raw voltages (X,Y,Z) values.</span></div><div class='line' id='LC1215'><span class="cm"> * \param[out] gyroscope The current sensor gyroscope raw voltages (X,Y,Z) values.</span></div><div class='line' id='LC1216'><span class="cm"> * \param[out] temperature The temperature raw voltages value of the sensor.</span></div><div class='line' id='LC1217'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1218'><span class="cm"> */</span></div><div class='line' id='LC1219'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getRawVoltageMeasurements</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetometer</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">accelerometer</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">gyroscope</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">temperature</span><span class="p">);</span></div><div class='line' id='LC1220'><br/></div><div class='line' id='LC1221'><span class="cm">/**</span></div><div class='line' id='LC1222'><span class="cm"> * \brief Gets the values in the Calibrated IMU Measurements register.</span></div><div class='line' id='LC1223'><span class="cm"> *</span></div><div class='line' id='LC1224'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1225'><span class="cm"> * \param[out] magnetic The current sensor calibrated magnetic measurements (X,Y,Z) values.</span></div><div class='line' id='LC1226'><span class="cm"> * \param[out] acceleration The current sensor calibrated acceleration measurements (X,Y,Z) values.</span></div><div class='line' id='LC1227'><span class="cm"> * \param[out] angularRate The current sensor calibrated angular rate measurements (X,Y,Z) values.</span></div><div class='line' id='LC1228'><span class="cm"> * \param[out] temperature The temperature value of the sensor.</span></div><div class='line' id='LC1229'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1230'><span class="cm"> */</span></div><div class='line' id='LC1231'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getCalibratedImuMeasurements</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">magnetic</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">acceleration</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">angularRate</span><span class="p">,</span> <span class="kt">double</span><span class="o">*</span> <span class="n">temperature</span><span class="p">);</span></div><div class='line' id='LC1232'><br/></div><div class='line' id='LC1233'><span class="cm">/**</span></div><div class='line' id='LC1234'><span class="cm"> * \brief Gets the values in the Kalman Filter State Vector register.</span></div><div class='line' id='LC1235'><span class="cm"> *</span></div><div class='line' id='LC1236'><span class="cm"> * \param[in] vn100 Pointer to the Vn100 control object.</span></div><div class='line' id='LC1237'><span class="cm"> * \param[out] attitude The current sensor Quaterion values.</span></div><div class='line' id='LC1238'><span class="cm"> * \param[out] gyroscopeBias The current sensor gyroscope bias (X,Y,Z) values.</span></div><div class='line' id='LC1239'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC1240'><span class="cm"> */</span></div><div class='line' id='LC1241'><span class="n">VN_ERROR_CODE</span> <span class="nf">vn100_getKalmanFilterStateVector</span><span class="p">(</span><span class="n">Vn100</span><span class="o">*</span> <span class="n">vn100</span><span class="p">,</span> <span class="n">VnQuaternion</span><span class="o">*</span> <span class="n">attitude</span><span class="p">,</span> <span class="n">VnVector3</span><span class="o">*</span> <span class="n">gyroscopeBias</span><span class="p">);</span></div><div class='line' id='LC1242'><br/></div><div class='line' id='LC1243'><br/></div><div class='line' id='LC1244'><span class="cm">/* VN100_CODE_GENERATION_SPOT_0_END */</span></div><div class='line' id='LC1245'><br/></div><div class='line' id='LC1246'><span class="cp">#ifdef __cplusplus</span></div><div class='line' id='LC1247'><span class="p">}</span></div><div class='line' id='LC1248'><span class="cp">#endif</span></div><div class='line' id='LC1249'><br/></div><div class='line' id='LC1250'><span class="cp">#endif </span><span class="cm">/* _VN100_H_ */</span><span class="cp"></span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>

        <a href="#jump-to-line" rel="facebox" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
        <div id="jump-to-line" style="display:none">
          <h2>Jump to Line</h2>
          <form accept-charset="UTF-8" class="js-jump-to-line-form">
            <input class="textfield js-jump-to-line-field" type="text">
            <div class="full-button">
              <button type="submit" class="button">Go</button>
            </div>
          </form>
        </div>

      </div>
    </div>
</div>

<div id="js-frame-loading-template" class="frame frame-loading large-loading-area" style="display:none;">
  <img class="js-frame-loading-spinner" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-128.gif?1347543527" height="64" width="64">
</div>


        </div>
      </div>
      <div class="modal-backdrop"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer">
  <div class="container clearfix">

      <dl class="footer_nav">
        <dt>GitHub</dt>
        <dd><a href="https://github.com/about">About us</a></dd>
        <dd><a href="https://github.com/blog">Blog</a></dd>
        <dd><a href="https://github.com/contact">Contact &amp; support</a></dd>
        <dd><a href="http://enterprise.github.com/">GitHub Enterprise</a></dd>
        <dd><a href="http://status.github.com/">Site status</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Applications</dt>
        <dd><a href="http://mac.github.com/">GitHub for Mac</a></dd>
        <dd><a href="http://windows.github.com/">GitHub for Windows</a></dd>
        <dd><a href="http://eclipse.github.com/">GitHub for Eclipse</a></dd>
        <dd><a href="http://mobile.github.com/">GitHub mobile apps</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Services</dt>
        <dd><a href="http://get.gaug.es/">Gauges: Web analytics</a></dd>
        <dd><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></dd>
        <dd><a href="https://gist.github.com">Gist: Code snippets</a></dd>
        <dd><a href="http://jobs.github.com/">Job board</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Documentation</dt>
        <dd><a href="http://help.github.com/">GitHub Help</a></dd>
        <dd><a href="http://developer.github.com/">Developer API</a></dd>
        <dd><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></dd>
        <dd><a href="http://pages.github.com/">GitHub Pages</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>More</dt>
        <dd><a href="http://training.github.com/">Training</a></dd>
        <dd><a href="https://github.com/edu">Students &amp; teachers</a></dd>
        <dd><a href="http://shop.github.com">The Shop</a></dd>
        <dd><a href="/plans">Plans &amp; pricing</a></dd>
        <dd><a href="http://octodex.github.com/">The Octodex</a></dd>
      </dl>

      <hr class="footer-divider">


    <p class="right">&copy; 2013 <span title="0.31652s from fe16.rs.github.com">GitHub</span>, Inc. All rights reserved.</p>
    <a class="left" href="https://github.com/">
      <span class="mega-icon mega-icon-invertocat"></span>
    </a>
    <ul id="legal">
        <li><a href="https://github.com/site/terms">Terms of Service</a></li>
        <li><a href="https://github.com/site/privacy">Privacy</a></li>
        <li><a href="https://github.com/security">Security</a></li>
    </ul>

  </div><!-- /.container -->

</div><!-- /.#footer -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/alexsleat/projectChimaera/suggestions/commit">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-icon mega-icon-normalscreen"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="mini-icon mini-icon-brightness"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="mini-icon mini-icon-remove-close ajax-error-dismiss"></a>
    </div>

    
    
    <span id='server_response_time' data-time='0.31709' data-host='fe16'></span>
    
  </body>
</html>

